%skeleton "lalr1.cc" /* -*- C++ -*- */
%require "3.2"
%defines

%define api.token.constructor
%define api.location.file none
%define api.value.type variant
%define parse.assert
%define parse.trace
%define parse.error verbose

%code requires {
  class driver;
  class RootAST;
  class ExprAST;
  class FunctionAST;
  class PrototypeAST;
  class IfExprAST;
  class LetExprAST;
  class DefAST;
  
  // Tell Flex the lexer's prototype ...
# define YY_DECL \
  yy::parser::symbol_type yylex (driver& drv)
}

%param { driver& drv }

%locations

%code {
# include "driver.hpp"
YY_DECL;
}

%define api.token.prefix {TOK_}
%token
  EOF  0  "end of file"
  COLON      ":"
  YIELD      "yield"
  SEMICOLON  ";"
  COMMA      ","
  MINUS      "-"
  PLUS       "+"
  STAR       "*"
  SLASH      "/"
  MOD        "%"
  ALT        "|"
  LE         "<="
  LT         "<"
  EQ         "=="
  NEQ        "<>"
  GE         ">="
  GT         ">"
  BIND       "="
  TRUE       "true"
  FALSE      "false"
  EXTERN     "external"
  DEF        "function"
  IF         "if"
  SET        "set"
  AND        "and"
  OR         "or"
  NOT        "not"
  LET        "let"
  MAIN	     "main"
  END        "end"
  LBRACE     "{"
  RBRACE     "}"
  FOR        "for"
  IN         "in"
  USING      "using"
  DO         "do"
  RANGE      "range"
  LPAREN     "("
  RPAREN     ")"
;

%token <std::string> IDENTIFIER "id"
%token <int> NUMBER "number"

%type <std::vector<DefAST*>> deflist
%type <DefAST*> def
%type <ExprAST*> boolexpr
%type <FunctionAST*> funcdef
%type <PrototypeAST*> extdef
%type <PrototypeAST*> prototype
%type <std::vector<std::string>> params
%type <std::vector<ExprAST*>> arglist
%type <std::vector<ExprAST*>> args
%type <IfExprAST*> condexpr
%type <LetExprAST*> letexpr
%type <std::vector<std::pair<ExprAST*, ExprAST*>>> pairs;
%type <std::pair<ExprAST*, ExprAST*>> pair;
%type <std::vector<std::pair<std::string, ExprAST*>>> bindings;
%type <std::pair<std::string, ExprAST*>> binding;
%type <ExprAST*> literal 
%type <ExprAST*> relexpr
%type <ExprAST*> expr
%type <ExprAST*> for_expr
%type <std::vector<std::string>> using_clause 
%type <std::vector<std::string>> id_list
%%

%start startsymb;

startsymb:
  deflist               { drv.root = $1;};

deflist:
  def deflist           { $2.insert($2.begin(),$1); $$ = $2; }
| def                   { std::vector<DefAST*> D = {$1}; $$ = D; };

def:
  extdef                { $$ = $1; }
| funcdef               { $$ = $1; };

extdef:
  "external" prototype  { $2->setext(); $$ = $2; };

funcdef:
  "function" prototype expr "end"  { $$ = new FunctionAST($2,$3); };

prototype:
  "id" LPAREN params RPAREN   { $$ = new PrototypeAST($1,$3); };

params:
  %empty                { std::vector<std::string> params; $$ = params; }
| "id" params           { $2.insert($2.begin(),$1); $$ = $2;};
 
%nonassoc "<" "==" "<>" "<=" ">" ">=";
%left "+" "-";
%left "*" "/" "%";
%nonassoc UMINUS;
%left "or";
%left "and";
%nonassoc NEGATE;

expr:
  expr "+" expr          { $$ = new BinaryExprAST("+",$1,$3); }
| expr "-" expr          { $$ = new BinaryExprAST("-",$1,$3); }
| expr "*" expr          { $$ = new BinaryExprAST("*",$1,$3); }
| expr "/" expr          { $$ = new BinaryExprAST("/",$1,$3); }
| expr "%" expr          { $$ = new BinaryExprAST("%",$1,$3); }
| "-" expr %prec UMINUS  { $$ = new UnaryExprAST("-",$2); }
| "(" expr ")"           { $$ = $2; }
| "id"                   { $$ = new IdeExprAST($1); }
| "id" "(" arglist ")"   { $$ = new CallExprAST($1,$3); }
| "number"               { $$ = new NumberExprAST($1); }
| condexpr               { $$ = $1; }
| letexpr                { $$ = $1; }
| YIELD expr             { $$ = new YieldExprAST($2); }
| SET LBRACE bindings RBRACE   { $$ = new SetExprAST($3); }
| for_expr                { $$ = $1; }
;


arglist: 
  %empty                 { std::vector<ExprAST*> args; $$ = args; }
| args                   { $$ = $1; };

args:
  expr                   { std::vector<ExprAST*> V = {$1}; $$ = V; }
| expr "," args          { $3.insert($3.begin(),$1); $$ = $3; };

condexpr:
 "if" pairs "end"        { $$ = new IfExprAST($2); };


pairs:
  pair                   { std::vector<std::pair<ExprAST*, ExprAST*>> P = {$1}; $$ = P; }
| pair ";" pairs         { $3.insert($3.begin(),$1); $$ = $3; };

pair: 
  boolexpr ":" expr      { std::pair<ExprAST*,ExprAST*> P ($1,$3); $$ = P; };
  
boolexpr:
  boolexpr "and" boolexpr { $$ = new BinaryExprAST("and",$1,$3); }
| boolexpr "or" boolexpr  { $$ = new BinaryExprAST("or",$1,$3); }
| "not" boolexpr  %prec NEGATE { $$ = new UnaryExprAST("not",$2); }
| literal                 { $$ = $1; }
| relexpr                 { $$ = $1; };

literal:
  "true"                  { $$ = new NumberExprAST(1); }
| "false"                 { $$ = new NumberExprAST(0); };

relexpr:
  expr "<"  expr          { $$ = new BinaryExprAST("<",$1,$3); }
| expr "==" expr          { $$ = new BinaryExprAST("=",$1,$3); }
| expr "<>" expr          { $$ = new BinaryExprAST("<>",$1,$3); }
| expr "<=" expr          { $$ = new BinaryExprAST("<=",$1,$3); }
| expr ">"  expr          { $$ = new BinaryExprAST(">",$1,$3); }
| expr ">=" expr          { $$ = new BinaryExprAST(">=",$1,$3); }

letexpr: 
  "let" bindings "in" expr "end" { $$ = new LetExprAST($2,$4); };

bindings:
  binding                 { std::vector<std::pair<std::string, ExprAST*>> B = {$1}; $$ = B; }
| binding ";" bindings    { $3.insert($3.begin(),$1); $$ = $3; };
  
binding:
  "id" "=" expr           { $$ = std::make_pair($1, $3); };

for_expr:
    FOR IDENTIFIER IN RANGE LPAREN expr RPAREN using_clause DO expr END {
        $$ = new ForExprAST($2, $6, $8, $10);
    }
;

using_clause:
    /* Clausola opzionale */
    USING id_list   { $$ = $2; }
    |
    /* Clausola vuota */
    { $$ = std::vector<std::string>(); }
;

id_list:
    IDENTIFIER              { $$ = std::vector<std::string>{ $1 }; }
    | id_list COMMA IDENTIFIER { $1.push_back($3); $$ = $1; }
;

%%

void yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
