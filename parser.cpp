// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.hpp"


// Unqualified %code blocks.
#line 31 "parser.yy"

# include "driver.hpp"
YY_DECL;

#line 51 "parser.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 143 "parser.cpp"

  /// Build a parser object.
  parser::parser (driver& drv_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      drv (drv_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_def: // def
        value.YY_MOVE_OR_COPY< DefAST* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr: // expr
      case symbol_kind::S_boolexpr: // boolexpr
      case symbol_kind::S_literal: // literal
      case symbol_kind::S_relexpr: // relexpr
      case symbol_kind::S_for_expr: // for_expr
        value.YY_MOVE_OR_COPY< ExprAST* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_funcdef: // funcdef
        value.YY_MOVE_OR_COPY< FunctionAST* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_condexpr: // condexpr
        value.YY_MOVE_OR_COPY< IfExprAST* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_letexpr: // letexpr
        value.YY_MOVE_OR_COPY< LetExprAST* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_extdef: // extdef
      case symbol_kind::S_prototype: // prototype
        value.YY_MOVE_OR_COPY< PrototypeAST* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMBER: // "number"
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_pair: // pair
        value.YY_MOVE_OR_COPY< std::pair<ExprAST*, ExprAST*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_binding: // binding
        value.YY_MOVE_OR_COPY< std::pair<std::string, ExprAST*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // "id"
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_deflist: // deflist
        value.YY_MOVE_OR_COPY< std::vector<DefAST*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_arglist: // arglist
      case symbol_kind::S_args: // args
        value.YY_MOVE_OR_COPY< std::vector<ExprAST*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_pairs: // pairs
        value.YY_MOVE_OR_COPY< std::vector<std::pair<ExprAST*, ExprAST*>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_bindings: // bindings
        value.YY_MOVE_OR_COPY< std::vector<std::pair<std::string, ExprAST*>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_params: // params
      case symbol_kind::S_using_clause: // using_clause
      case symbol_kind::S_id_list: // id_list
        value.YY_MOVE_OR_COPY< std::vector<std::string> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_def: // def
        value.move< DefAST* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr: // expr
      case symbol_kind::S_boolexpr: // boolexpr
      case symbol_kind::S_literal: // literal
      case symbol_kind::S_relexpr: // relexpr
      case symbol_kind::S_for_expr: // for_expr
        value.move< ExprAST* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_funcdef: // funcdef
        value.move< FunctionAST* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_condexpr: // condexpr
        value.move< IfExprAST* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_letexpr: // letexpr
        value.move< LetExprAST* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_extdef: // extdef
      case symbol_kind::S_prototype: // prototype
        value.move< PrototypeAST* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMBER: // "number"
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_pair: // pair
        value.move< std::pair<ExprAST*, ExprAST*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_binding: // binding
        value.move< std::pair<std::string, ExprAST*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // "id"
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_deflist: // deflist
        value.move< std::vector<DefAST*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_arglist: // arglist
      case symbol_kind::S_args: // args
        value.move< std::vector<ExprAST*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_pairs: // pairs
        value.move< std::vector<std::pair<ExprAST*, ExprAST*>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_bindings: // bindings
        value.move< std::vector<std::pair<std::string, ExprAST*>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_params: // params
      case symbol_kind::S_using_clause: // using_clause
      case symbol_kind::S_id_list: // id_list
        value.move< std::vector<std::string> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_def: // def
        value.copy< DefAST* > (that.value);
        break;

      case symbol_kind::S_expr: // expr
      case symbol_kind::S_boolexpr: // boolexpr
      case symbol_kind::S_literal: // literal
      case symbol_kind::S_relexpr: // relexpr
      case symbol_kind::S_for_expr: // for_expr
        value.copy< ExprAST* > (that.value);
        break;

      case symbol_kind::S_funcdef: // funcdef
        value.copy< FunctionAST* > (that.value);
        break;

      case symbol_kind::S_condexpr: // condexpr
        value.copy< IfExprAST* > (that.value);
        break;

      case symbol_kind::S_letexpr: // letexpr
        value.copy< LetExprAST* > (that.value);
        break;

      case symbol_kind::S_extdef: // extdef
      case symbol_kind::S_prototype: // prototype
        value.copy< PrototypeAST* > (that.value);
        break;

      case symbol_kind::S_NUMBER: // "number"
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_pair: // pair
        value.copy< std::pair<ExprAST*, ExprAST*> > (that.value);
        break;

      case symbol_kind::S_binding: // binding
        value.copy< std::pair<std::string, ExprAST*> > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // "id"
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_deflist: // deflist
        value.copy< std::vector<DefAST*> > (that.value);
        break;

      case symbol_kind::S_arglist: // arglist
      case symbol_kind::S_args: // args
        value.copy< std::vector<ExprAST*> > (that.value);
        break;

      case symbol_kind::S_pairs: // pairs
        value.copy< std::vector<std::pair<ExprAST*, ExprAST*>> > (that.value);
        break;

      case symbol_kind::S_bindings: // bindings
        value.copy< std::vector<std::pair<std::string, ExprAST*>> > (that.value);
        break;

      case symbol_kind::S_params: // params
      case symbol_kind::S_using_clause: // using_clause
      case symbol_kind::S_id_list: // id_list
        value.copy< std::vector<std::string> > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_def: // def
        value.move< DefAST* > (that.value);
        break;

      case symbol_kind::S_expr: // expr
      case symbol_kind::S_boolexpr: // boolexpr
      case symbol_kind::S_literal: // literal
      case symbol_kind::S_relexpr: // relexpr
      case symbol_kind::S_for_expr: // for_expr
        value.move< ExprAST* > (that.value);
        break;

      case symbol_kind::S_funcdef: // funcdef
        value.move< FunctionAST* > (that.value);
        break;

      case symbol_kind::S_condexpr: // condexpr
        value.move< IfExprAST* > (that.value);
        break;

      case symbol_kind::S_letexpr: // letexpr
        value.move< LetExprAST* > (that.value);
        break;

      case symbol_kind::S_extdef: // extdef
      case symbol_kind::S_prototype: // prototype
        value.move< PrototypeAST* > (that.value);
        break;

      case symbol_kind::S_NUMBER: // "number"
        value.move< int > (that.value);
        break;

      case symbol_kind::S_pair: // pair
        value.move< std::pair<ExprAST*, ExprAST*> > (that.value);
        break;

      case symbol_kind::S_binding: // binding
        value.move< std::pair<std::string, ExprAST*> > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // "id"
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_deflist: // deflist
        value.move< std::vector<DefAST*> > (that.value);
        break;

      case symbol_kind::S_arglist: // arglist
      case symbol_kind::S_args: // args
        value.move< std::vector<ExprAST*> > (that.value);
        break;

      case symbol_kind::S_pairs: // pairs
        value.move< std::vector<std::pair<ExprAST*, ExprAST*>> > (that.value);
        break;

      case symbol_kind::S_bindings: // bindings
        value.move< std::vector<std::pair<std::string, ExprAST*>> > (that.value);
        break;

      case symbol_kind::S_params: // params
      case symbol_kind::S_using_clause: // using_clause
      case symbol_kind::S_id_list: // id_list
        value.move< std::vector<std::string> > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (drv));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_def: // def
        yylhs.value.emplace< DefAST* > ();
        break;

      case symbol_kind::S_expr: // expr
      case symbol_kind::S_boolexpr: // boolexpr
      case symbol_kind::S_literal: // literal
      case symbol_kind::S_relexpr: // relexpr
      case symbol_kind::S_for_expr: // for_expr
        yylhs.value.emplace< ExprAST* > ();
        break;

      case symbol_kind::S_funcdef: // funcdef
        yylhs.value.emplace< FunctionAST* > ();
        break;

      case symbol_kind::S_condexpr: // condexpr
        yylhs.value.emplace< IfExprAST* > ();
        break;

      case symbol_kind::S_letexpr: // letexpr
        yylhs.value.emplace< LetExprAST* > ();
        break;

      case symbol_kind::S_extdef: // extdef
      case symbol_kind::S_prototype: // prototype
        yylhs.value.emplace< PrototypeAST* > ();
        break;

      case symbol_kind::S_NUMBER: // "number"
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_pair: // pair
        yylhs.value.emplace< std::pair<ExprAST*, ExprAST*> > ();
        break;

      case symbol_kind::S_binding: // binding
        yylhs.value.emplace< std::pair<std::string, ExprAST*> > ();
        break;

      case symbol_kind::S_IDENTIFIER: // "id"
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_deflist: // deflist
        yylhs.value.emplace< std::vector<DefAST*> > ();
        break;

      case symbol_kind::S_arglist: // arglist
      case symbol_kind::S_args: // args
        yylhs.value.emplace< std::vector<ExprAST*> > ();
        break;

      case symbol_kind::S_pairs: // pairs
        yylhs.value.emplace< std::vector<std::pair<ExprAST*, ExprAST*>> > ();
        break;

      case symbol_kind::S_bindings: // bindings
        yylhs.value.emplace< std::vector<std::pair<std::string, ExprAST*>> > ();
        break;

      case symbol_kind::S_params: // params
      case symbol_kind::S_using_clause: // using_clause
      case symbol_kind::S_id_list: // id_list
        yylhs.value.emplace< std::vector<std::string> > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // startsymb: deflist
#line 108 "parser.yy"
                        { drv.root = yystack_[0].value.as < std::vector<DefAST*> > ();}
#line 877 "parser.cpp"
    break;

  case 3: // deflist: def deflist
#line 111 "parser.yy"
                        { yystack_[0].value.as < std::vector<DefAST*> > ().insert(yystack_[0].value.as < std::vector<DefAST*> > ().begin(),yystack_[1].value.as < DefAST* > ()); yylhs.value.as < std::vector<DefAST*> > () = yystack_[0].value.as < std::vector<DefAST*> > (); }
#line 883 "parser.cpp"
    break;

  case 4: // deflist: def
#line 112 "parser.yy"
                        { std::vector<DefAST*> D = {yystack_[0].value.as < DefAST* > ()}; yylhs.value.as < std::vector<DefAST*> > () = D; }
#line 889 "parser.cpp"
    break;

  case 5: // def: extdef
#line 115 "parser.yy"
                        { yylhs.value.as < DefAST* > () = yystack_[0].value.as < PrototypeAST* > (); }
#line 895 "parser.cpp"
    break;

  case 6: // def: funcdef
#line 116 "parser.yy"
                        { yylhs.value.as < DefAST* > () = yystack_[0].value.as < FunctionAST* > (); }
#line 901 "parser.cpp"
    break;

  case 7: // extdef: "external" prototype
#line 119 "parser.yy"
                        { yystack_[0].value.as < PrototypeAST* > ()->setext(); yylhs.value.as < PrototypeAST* > () = yystack_[0].value.as < PrototypeAST* > (); }
#line 907 "parser.cpp"
    break;

  case 8: // funcdef: "function" prototype expr "end"
#line 122 "parser.yy"
                                   { yylhs.value.as < FunctionAST* > () = new FunctionAST(yystack_[2].value.as < PrototypeAST* > (),yystack_[1].value.as < ExprAST* > ()); }
#line 913 "parser.cpp"
    break;

  case 9: // prototype: "id" "(" params ")"
#line 125 "parser.yy"
                              { yylhs.value.as < PrototypeAST* > () = new PrototypeAST(yystack_[3].value.as < std::string > (),yystack_[1].value.as < std::vector<std::string> > ()); }
#line 919 "parser.cpp"
    break;

  case 10: // params: %empty
#line 128 "parser.yy"
                        { std::vector<std::string> params; yylhs.value.as < std::vector<std::string> > () = params; }
#line 925 "parser.cpp"
    break;

  case 11: // params: "id" params
#line 129 "parser.yy"
                        { yystack_[0].value.as < std::vector<std::string> > ().insert(yystack_[0].value.as < std::vector<std::string> > ().begin(),yystack_[1].value.as < std::string > ()); yylhs.value.as < std::vector<std::string> > () = yystack_[0].value.as < std::vector<std::string> > ();}
#line 931 "parser.cpp"
    break;

  case 12: // expr: expr "+" expr
#line 140 "parser.yy"
                         { yylhs.value.as < ExprAST* > () = new BinaryExprAST("+",yystack_[2].value.as < ExprAST* > (),yystack_[0].value.as < ExprAST* > ()); }
#line 937 "parser.cpp"
    break;

  case 13: // expr: expr "-" expr
#line 141 "parser.yy"
                         { yylhs.value.as < ExprAST* > () = new BinaryExprAST("-",yystack_[2].value.as < ExprAST* > (),yystack_[0].value.as < ExprAST* > ()); }
#line 943 "parser.cpp"
    break;

  case 14: // expr: expr "*" expr
#line 142 "parser.yy"
                         { yylhs.value.as < ExprAST* > () = new BinaryExprAST("*",yystack_[2].value.as < ExprAST* > (),yystack_[0].value.as < ExprAST* > ()); }
#line 949 "parser.cpp"
    break;

  case 15: // expr: expr "/" expr
#line 143 "parser.yy"
                         { yylhs.value.as < ExprAST* > () = new BinaryExprAST("/",yystack_[2].value.as < ExprAST* > (),yystack_[0].value.as < ExprAST* > ()); }
#line 955 "parser.cpp"
    break;

  case 16: // expr: expr "%" expr
#line 144 "parser.yy"
                         { yylhs.value.as < ExprAST* > () = new BinaryExprAST("%",yystack_[2].value.as < ExprAST* > (),yystack_[0].value.as < ExprAST* > ()); }
#line 961 "parser.cpp"
    break;

  case 17: // expr: "-" expr
#line 145 "parser.yy"
                         { yylhs.value.as < ExprAST* > () = new UnaryExprAST("-",yystack_[0].value.as < ExprAST* > ()); }
#line 967 "parser.cpp"
    break;

  case 18: // expr: "(" expr ")"
#line 146 "parser.yy"
                         { yylhs.value.as < ExprAST* > () = yystack_[1].value.as < ExprAST* > (); }
#line 973 "parser.cpp"
    break;

  case 19: // expr: "id"
#line 147 "parser.yy"
                         { yylhs.value.as < ExprAST* > () = new IdeExprAST(yystack_[0].value.as < std::string > ()); }
#line 979 "parser.cpp"
    break;

  case 20: // expr: "id" "(" arglist ")"
#line 148 "parser.yy"
                         { yylhs.value.as < ExprAST* > () = new CallExprAST(yystack_[3].value.as < std::string > (),yystack_[1].value.as < std::vector<ExprAST*> > ()); }
#line 985 "parser.cpp"
    break;

  case 21: // expr: "number"
#line 149 "parser.yy"
                         { yylhs.value.as < ExprAST* > () = new NumberExprAST(yystack_[0].value.as < int > ()); }
#line 991 "parser.cpp"
    break;

  case 22: // expr: condexpr
#line 150 "parser.yy"
                         { yylhs.value.as < ExprAST* > () = yystack_[0].value.as < IfExprAST* > (); }
#line 997 "parser.cpp"
    break;

  case 23: // expr: letexpr
#line 151 "parser.yy"
                         { yylhs.value.as < ExprAST* > () = yystack_[0].value.as < LetExprAST* > (); }
#line 1003 "parser.cpp"
    break;

  case 24: // expr: "yield" expr
#line 152 "parser.yy"
                         { yylhs.value.as < ExprAST* > () = new YieldExprAST(yystack_[0].value.as < ExprAST* > ()); }
#line 1009 "parser.cpp"
    break;

  case 25: // expr: "set" "{" bindings "}"
#line 153 "parser.yy"
                               { yylhs.value.as < ExprAST* > () = new SetExprAST(yystack_[1].value.as < std::vector<std::pair<std::string, ExprAST*>> > ()); }
#line 1015 "parser.cpp"
    break;

  case 26: // expr: for_expr
#line 154 "parser.yy"
                          { yylhs.value.as < ExprAST* > () = yystack_[0].value.as < ExprAST* > (); }
#line 1021 "parser.cpp"
    break;

  case 27: // arglist: %empty
#line 159 "parser.yy"
                         { std::vector<ExprAST*> args; yylhs.value.as < std::vector<ExprAST*> > () = args; }
#line 1027 "parser.cpp"
    break;

  case 28: // arglist: args
#line 160 "parser.yy"
                         { yylhs.value.as < std::vector<ExprAST*> > () = yystack_[0].value.as < std::vector<ExprAST*> > (); }
#line 1033 "parser.cpp"
    break;

  case 29: // args: expr
#line 163 "parser.yy"
                         { std::vector<ExprAST*> V = {yystack_[0].value.as < ExprAST* > ()}; yylhs.value.as < std::vector<ExprAST*> > () = V; }
#line 1039 "parser.cpp"
    break;

  case 30: // args: expr "," args
#line 164 "parser.yy"
                         { yystack_[0].value.as < std::vector<ExprAST*> > ().insert(yystack_[0].value.as < std::vector<ExprAST*> > ().begin(),yystack_[2].value.as < ExprAST* > ()); yylhs.value.as < std::vector<ExprAST*> > () = yystack_[0].value.as < std::vector<ExprAST*> > (); }
#line 1045 "parser.cpp"
    break;

  case 31: // condexpr: "if" pairs "end"
#line 167 "parser.yy"
                         { yylhs.value.as < IfExprAST* > () = new IfExprAST(yystack_[1].value.as < std::vector<std::pair<ExprAST*, ExprAST*>> > ()); }
#line 1051 "parser.cpp"
    break;

  case 32: // pairs: pair
#line 171 "parser.yy"
                         { std::vector<std::pair<ExprAST*, ExprAST*>> P = {yystack_[0].value.as < std::pair<ExprAST*, ExprAST*> > ()}; yylhs.value.as < std::vector<std::pair<ExprAST*, ExprAST*>> > () = P; }
#line 1057 "parser.cpp"
    break;

  case 33: // pairs: pair ";" pairs
#line 172 "parser.yy"
                         { yystack_[0].value.as < std::vector<std::pair<ExprAST*, ExprAST*>> > ().insert(yystack_[0].value.as < std::vector<std::pair<ExprAST*, ExprAST*>> > ().begin(),yystack_[2].value.as < std::pair<ExprAST*, ExprAST*> > ()); yylhs.value.as < std::vector<std::pair<ExprAST*, ExprAST*>> > () = yystack_[0].value.as < std::vector<std::pair<ExprAST*, ExprAST*>> > (); }
#line 1063 "parser.cpp"
    break;

  case 34: // pair: boolexpr ":" expr
#line 175 "parser.yy"
                         { std::pair<ExprAST*,ExprAST*> P (yystack_[2].value.as < ExprAST* > (),yystack_[0].value.as < ExprAST* > ()); yylhs.value.as < std::pair<ExprAST*, ExprAST*> > () = P; }
#line 1069 "parser.cpp"
    break;

  case 35: // boolexpr: boolexpr "and" boolexpr
#line 178 "parser.yy"
                          { yylhs.value.as < ExprAST* > () = new BinaryExprAST("and",yystack_[2].value.as < ExprAST* > (),yystack_[0].value.as < ExprAST* > ()); }
#line 1075 "parser.cpp"
    break;

  case 36: // boolexpr: boolexpr "or" boolexpr
#line 179 "parser.yy"
                          { yylhs.value.as < ExprAST* > () = new BinaryExprAST("or",yystack_[2].value.as < ExprAST* > (),yystack_[0].value.as < ExprAST* > ()); }
#line 1081 "parser.cpp"
    break;

  case 37: // boolexpr: "not" boolexpr
#line 180 "parser.yy"
                               { yylhs.value.as < ExprAST* > () = new UnaryExprAST("not",yystack_[0].value.as < ExprAST* > ()); }
#line 1087 "parser.cpp"
    break;

  case 38: // boolexpr: literal
#line 181 "parser.yy"
                          { yylhs.value.as < ExprAST* > () = yystack_[0].value.as < ExprAST* > (); }
#line 1093 "parser.cpp"
    break;

  case 39: // boolexpr: relexpr
#line 182 "parser.yy"
                          { yylhs.value.as < ExprAST* > () = yystack_[0].value.as < ExprAST* > (); }
#line 1099 "parser.cpp"
    break;

  case 40: // literal: "true"
#line 185 "parser.yy"
                          { yylhs.value.as < ExprAST* > () = new NumberExprAST(1); }
#line 1105 "parser.cpp"
    break;

  case 41: // literal: "false"
#line 186 "parser.yy"
                          { yylhs.value.as < ExprAST* > () = new NumberExprAST(0); }
#line 1111 "parser.cpp"
    break;

  case 42: // relexpr: expr "<" expr
#line 189 "parser.yy"
                          { yylhs.value.as < ExprAST* > () = new BinaryExprAST("<",yystack_[2].value.as < ExprAST* > (),yystack_[0].value.as < ExprAST* > ()); }
#line 1117 "parser.cpp"
    break;

  case 43: // relexpr: expr "==" expr
#line 190 "parser.yy"
                          { yylhs.value.as < ExprAST* > () = new BinaryExprAST("=",yystack_[2].value.as < ExprAST* > (),yystack_[0].value.as < ExprAST* > ()); }
#line 1123 "parser.cpp"
    break;

  case 44: // relexpr: expr "<>" expr
#line 191 "parser.yy"
                          { yylhs.value.as < ExprAST* > () = new BinaryExprAST("<>",yystack_[2].value.as < ExprAST* > (),yystack_[0].value.as < ExprAST* > ()); }
#line 1129 "parser.cpp"
    break;

  case 45: // relexpr: expr "<=" expr
#line 192 "parser.yy"
                          { yylhs.value.as < ExprAST* > () = new BinaryExprAST("<=",yystack_[2].value.as < ExprAST* > (),yystack_[0].value.as < ExprAST* > ()); }
#line 1135 "parser.cpp"
    break;

  case 46: // relexpr: expr ">" expr
#line 193 "parser.yy"
                          { yylhs.value.as < ExprAST* > () = new BinaryExprAST(">",yystack_[2].value.as < ExprAST* > (),yystack_[0].value.as < ExprAST* > ()); }
#line 1141 "parser.cpp"
    break;

  case 47: // relexpr: expr ">=" expr
#line 194 "parser.yy"
                          { yylhs.value.as < ExprAST* > () = new BinaryExprAST(">=",yystack_[2].value.as < ExprAST* > (),yystack_[0].value.as < ExprAST* > ()); }
#line 1147 "parser.cpp"
    break;

  case 48: // letexpr: "let" bindings "in" expr "end"
#line 197 "parser.yy"
                                 { yylhs.value.as < LetExprAST* > () = new LetExprAST(yystack_[3].value.as < std::vector<std::pair<std::string, ExprAST*>> > (),yystack_[1].value.as < ExprAST* > ()); }
#line 1153 "parser.cpp"
    break;

  case 49: // bindings: binding
#line 200 "parser.yy"
                          { std::vector<std::pair<std::string, ExprAST*>> B = {yystack_[0].value.as < std::pair<std::string, ExprAST*> > ()}; yylhs.value.as < std::vector<std::pair<std::string, ExprAST*>> > () = B; }
#line 1159 "parser.cpp"
    break;

  case 50: // bindings: binding ";" bindings
#line 201 "parser.yy"
                          { yystack_[0].value.as < std::vector<std::pair<std::string, ExprAST*>> > ().insert(yystack_[0].value.as < std::vector<std::pair<std::string, ExprAST*>> > ().begin(),yystack_[2].value.as < std::pair<std::string, ExprAST*> > ()); yylhs.value.as < std::vector<std::pair<std::string, ExprAST*>> > () = yystack_[0].value.as < std::vector<std::pair<std::string, ExprAST*>> > (); }
#line 1165 "parser.cpp"
    break;

  case 51: // binding: "id" "=" expr
#line 204 "parser.yy"
                          { yylhs.value.as < std::pair<std::string, ExprAST*> > () = std::make_pair(yystack_[2].value.as < std::string > (), yystack_[0].value.as < ExprAST* > ()); }
#line 1171 "parser.cpp"
    break;

  case 52: // for_expr: "for" "id" "in" "range" "(" expr ")" using_clause "do" expr "end"
#line 207 "parser.yy"
                                                                        {
        yylhs.value.as < ExprAST* > () = new ForExprAST(yystack_[9].value.as < std::string > (), yystack_[5].value.as < ExprAST* > (), yystack_[3].value.as < std::vector<std::string> > (), yystack_[1].value.as < ExprAST* > ());
    }
#line 1179 "parser.cpp"
    break;

  case 53: // using_clause: "using" id_list
#line 214 "parser.yy"
                    { yylhs.value.as < std::vector<std::string> > () = yystack_[0].value.as < std::vector<std::string> > (); }
#line 1185 "parser.cpp"
    break;

  case 54: // using_clause: %empty
#line 217 "parser.yy"
    { yylhs.value.as < std::vector<std::string> > () = std::vector<std::string>(); }
#line 1191 "parser.cpp"
    break;

  case 55: // id_list: "id"
#line 221 "parser.yy"
                            { yylhs.value.as < std::vector<std::string> > () = std::vector<std::string>{ yystack_[0].value.as < std::string > () }; }
#line 1197 "parser.cpp"
    break;

  case 56: // id_list: id_list "," "id"
#line 222 "parser.yy"
                               { yystack_[2].value.as < std::vector<std::string> > ().push_back(yystack_[0].value.as < std::string > ()); yylhs.value.as < std::vector<std::string> > () = yystack_[2].value.as < std::vector<std::string> > (); }
#line 1203 "parser.cpp"
    break;


#line 1207 "parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
  parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -39;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
      -6,   -23,   -23,     9,   -39,    -6,   -39,   -39,   -15,   -39,
      75,   -39,   -39,   -16,    75,    75,    49,    -4,   -12,   -11,
      75,    -8,   -39,    53,   -39,   -39,   -39,   -16,    -5,    85,
     -39,   -39,   -39,    49,   121,    11,    38,     0,   -39,   -39,
     -12,    26,    20,    52,    30,     4,    75,    75,    75,    75,
      75,    75,   -39,   -39,   -39,   -39,    75,    75,    75,    75,
      75,    75,   -39,    49,    75,    49,    49,    33,    75,    75,
     -12,    29,   -39,   142,    28,   -39,    -3,    -3,   -39,   -39,
     -39,    85,    85,    85,    85,    85,    85,   -39,    85,   -39,
      45,   -39,    85,   111,   -39,    36,    75,   -39,   -39,    75,
     -39,    12,    40,    31,    43,   -39,    79,    75,    46,   116,
     -39,   -39
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     0,     2,     4,     5,     6,     0,     7,
       0,     1,     3,    10,     0,     0,     0,     0,     0,     0,
       0,    19,    21,     0,    22,    23,    26,    10,     0,    24,
      17,    40,    41,     0,     0,     0,    32,     0,    38,    39,
       0,     0,     0,    49,     0,     0,    27,     0,     0,     0,
       0,     0,     8,    11,     9,    37,     0,     0,     0,     0,
       0,     0,    31,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    18,    29,     0,    28,    13,    12,    14,    15,
      16,    45,    42,    43,    44,    47,    46,    33,    34,    35,
      36,    25,    51,     0,    50,     0,     0,    20,    48,     0,
      30,     0,    54,     0,     0,    55,    53,     0,     0,     0,
      56,    52
  };

  const signed char
  parser::yypgoto_[] =
  {
     -39,   -39,    76,   -39,   -39,   -39,    96,    74,   -10,   -39,
       6,   -39,    42,   -39,   -32,   -39,   -39,   -39,   -38,   -39,
     -39,   -39,   -39
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,     3,     4,     5,     6,     7,     9,    28,    34,    74,
      75,    24,    35,    36,    37,    38,    39,    25,    42,    43,
      26,   104,   106
  };

  const signed char
  parser::yytable_[] =
  {
      23,    55,    67,    64,    29,    30,    49,    50,    51,    11,
      45,    47,    48,    49,    50,    51,     1,     2,     8,    47,
      48,    49,    50,    51,    13,    27,    65,    66,    40,    41,
      44,    46,    94,    89,    90,    54,    73,    76,    77,    78,
      79,    80,    62,    63,    72,    68,    81,    82,    83,    84,
      85,    86,   102,    14,    88,    69,    15,    70,    92,    93,
      47,    48,    49,    50,    51,    71,    91,    95,    97,    31,
      32,    65,   105,    16,    17,    99,   103,    33,    18,    14,
     107,    12,    15,    19,    52,   108,    73,   110,    20,   101,
      21,    22,    47,    48,    49,    50,    51,   109,    10,    16,
      17,    53,   100,     0,    18,    87,     0,     0,     0,    19,
       0,     0,     0,     0,    20,     0,    21,    22,    47,    48,
      49,    50,    51,    47,    48,    49,    50,    51,    47,    48,
      49,    50,    51,     0,    56,    57,    58,    59,    60,    61,
       0,     0,    98,     0,     0,     0,     0,   111,    96,    47,
      48,    49,    50,    51
  };

  const signed char
  parser::yycheck_[] =
  {
      10,    33,    40,     3,    14,    15,     9,    10,    11,     0,
      20,     7,     8,     9,    10,    11,    22,    23,    41,     7,
       8,     9,    10,    11,    39,    41,    26,    27,    32,    41,
      41,    39,    70,    65,    66,    40,    46,    47,    48,    49,
      50,    51,    31,     5,    40,    19,    56,    57,    58,    59,
      60,    61,    40,     4,    64,    35,     7,     5,    68,    69,
       7,     8,     9,    10,    11,    35,    33,    38,    40,    20,
      21,    26,    41,    24,    25,    39,    36,    28,    29,     4,
      37,     5,     7,    34,    31,     6,    96,    41,    39,    99,
      41,    42,     7,     8,     9,    10,    11,   107,     2,    24,
      25,    27,    96,    -1,    29,    63,    -1,    -1,    -1,    34,
      -1,    -1,    -1,    -1,    39,    -1,    41,    42,     7,     8,
       9,    10,    11,     7,     8,     9,    10,    11,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,    16,    17,    18,
      -1,    -1,    31,    -1,    -1,    -1,    -1,    31,     6,     7,
       8,     9,    10,    11
  };

  const signed char
  parser::yystos_[] =
  {
       0,    22,    23,    46,    47,    48,    49,    50,    41,    51,
      51,     0,    47,    39,     4,     7,    24,    25,    29,    34,
      39,    41,    42,    53,    56,    62,    65,    41,    52,    53,
      53,    20,    21,    28,    53,    57,    58,    59,    60,    61,
      32,    41,    63,    64,    41,    53,    39,     7,     8,     9,
      10,    11,    31,    52,    40,    59,    13,    14,    15,    16,
      17,    18,    31,     5,     3,    26,    27,    63,    19,    35,
       5,    35,    40,    53,    54,    55,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    57,    53,    59,
      59,    33,    53,    53,    63,    38,     6,    40,    31,    39,
      55,    53,    40,    36,    66,    41,    67,    37,     6,    53,
      41,    31
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    45,    46,    47,    47,    48,    48,    49,    50,    51,
      52,    52,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    54,    54,    55,
      55,    56,    57,    57,    58,    59,    59,    59,    59,    59,
      60,    60,    61,    61,    61,    61,    61,    61,    62,    63,
      63,    64,    65,    66,    66,    67,    67
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,     1,     1,     1,     2,     4,     4,
       0,     2,     3,     3,     3,     3,     3,     2,     3,     1,
       4,     1,     1,     1,     2,     4,     1,     0,     1,     1,
       3,     3,     1,     3,     3,     3,     3,     2,     1,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     5,     1,
       3,     3,    11,     2,     0,     1,     3
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "\":\"", "\"yield\"",
  "\";\"", "\",\"", "\"-\"", "\"+\"", "\"*\"", "\"/\"", "\"%\"", "\"|\"",
  "\"<=\"", "\"<\"", "\"==\"", "\"<>\"", "\">=\"", "\">\"", "\"=\"",
  "\"true\"", "\"false\"", "\"external\"", "\"function\"", "\"if\"",
  "\"set\"", "\"and\"", "\"or\"", "\"not\"", "\"let\"", "\"main\"",
  "\"end\"", "\"{\"", "\"}\"", "\"for\"", "\"in\"", "\"using\"", "\"do\"",
  "\"range\"", "\"(\"", "\")\"", "\"id\"", "\"number\"", "UMINUS",
  "NEGATE", "$accept", "startsymb", "deflist", "def", "extdef", "funcdef",
  "prototype", "params", "expr", "arglist", "args", "condexpr", "pairs",
  "pair", "boolexpr", "literal", "relexpr", "letexpr", "bindings",
  "binding", "for_expr", "using_clause", "id_list", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,   108,   108,   111,   112,   115,   116,   119,   122,   125,
     128,   129,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   159,   160,   163,
     164,   167,   171,   172,   175,   178,   179,   180,   181,   182,
     185,   186,   189,   190,   191,   192,   193,   194,   197,   200,
     201,   204,   207,   214,   217,   221,   222
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 1757 "parser.cpp"

#line 225 "parser.yy"


void yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
