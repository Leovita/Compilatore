#ifndef DRIVER_HH
# define DRIVER_HH
# include <string>
# include <map>
# include <variant>
# include <vector>
# include "parser.hpp"

typedef std::variant<std::string,int> lexval;
const lexval NONE = 0;

// Classe base dell'intera gerarchia di classi che rappresentano
// gli elementi del programma
class RootAST {
public:
  virtual ~RootAST() {};
  virtual RootAST *left() {return nullptr;};
  virtual RootAST *right() {return nullptr;};
  virtual lexval getLexVal() {return NONE;};
  virtual void visit() {};
};

/// DefAST - Classe base per tutti i nodi definizione
class DefAST : public RootAST {
public:
  virtual ~DefAST() {};
};

/// ExprAST - Classe base per tutti i nodi espressione
class ExprAST : public RootAST {
public:
  virtual ~ExprAST() {};
};

/// NumberExprAST - Classe per la rappresentazione di costanti numeriche
class NumberExprAST : public ExprAST {
private:
  int Val;

public:
  NumberExprAST(int Val);
  void visit();
  lexval getLexVal() const;
};

// driver.hpp

// Nuova classe per rappresentare l'espressione yield E
class YieldExprAST : public ExprAST {
private:
  ExprAST* Expr;  // L'espressione E

public:
  YieldExprAST(ExprAST* Expr);
  void visit() override;
  lexval getLexVal() const;
};

/// IdeExprAST - Classe per la rappresentazione di riferimenti a identificatori
class IdeExprAST : public ExprAST {
private:
  std::string Name;
  
public:
  IdeExprAST(std::string &Name);
  lexval getLexVal() const;
  void visit();
};

/// BinaryExprAST - Classe per la rappresentazione di operatori binary
class BinaryExprAST : public ExprAST {
private:
  std::string Op;
  ExprAST* LHS;
  ExprAST* RHS;

public:
  BinaryExprAST(std::string Op, ExprAST* LHS, ExprAST* RHS);
  void visit() override;
};

/// UnaryExprAST - Classe per la rappresentazione di operatori unari
class UnaryExprAST : public ExprAST {
private:
  std::string Op;
  ExprAST* RHS;

public:
  UnaryExprAST(std::string Op, ExprAST* RHS);
  void visit();
};

/// CallExprAST - Classe per la rappresentazione di chiamate di funzione
class CallExprAST : public ExprAST {
private:
  std::string Callee;
  std::vector<ExprAST*> Args;  // ASTs per la valutazione degli argomenti

public:
  CallExprAST(std::string Callee, std::vector<ExprAST*> Args);
  lexval getLexVal() const;
  void visit();
};

/// IfExprAST - Classe che rappresenta il costrutto "condizionale"
class IfExprAST : public ExprAST {
private:
  std::vector<std::pair<ExprAST*, ExprAST*>> IfThenSeq;
public:
  IfExprAST(std::vector<std::pair<ExprAST*, ExprAST*>> IfThenSeq);
  void visit();
};

/// LetExprAST - Classe per la rappresentazione di espressioni con definizione
/// di un ambiente locale
class LetExprAST : public ExprAST {
private:
  std::vector<std::pair<std::string, ExprAST*>> Bindings; 
  ExprAST* Body;
public:
  LetExprAST(std::vector<std::pair<std::string, ExprAST*>> Bindings, ExprAST* Body);
  void visit();
};

class PrototypeAST : public DefAST {
  private:
    std::string Name;
    bool External;
    std::vector<std::string> Params;

  public:
    PrototypeAST(std::string Name, std::vector<std::string> Params);
    lexval getLexVal() const;
    void setext();
    const std::vector<std::string> &getParams() const; 
    void visit();
    int paramssize();
};

class ForExprAST : public ExprAST {
private:
    std::string var;                    // Variabile di indice (i)
    ExprAST* range;                     // La funzione range(n)
    std::vector<std::string> usingVars;  // Variabili nella clausola 'using'
    ExprAST* body;  
public:
    ForExprAST(const std::string var, ExprAST* range, const std::vector<std::string> usingVars, ExprAST* body);
    void visit() override;
    lexval getLexVal() const;  
};

class SetExprAST : public ExprAST {
  private:
    std::vector<std::pair<std::string, ExprAST*>> Assignments;  // Lista di assegnamenti

  public:
    SetExprAST(std::vector<std::pair<std::string, ExprAST*>> Assignments);  // Costruttore
    void visit() override;  // Metodo per visitare il nodo
    lexval getLexVal() const;  // Restituisce sempre 0
  };

/// FunctionAST - Classe che rappresenta la definizione di una funzione
class FunctionAST : public DefAST {
private:
  PrototypeAST* Proto;
  ExprAST* Body;
  bool external;
  
public:
  FunctionAST(PrototypeAST* Proto, ExprAST* Body);
  void visit();
  int nparams();
};

// Classe che organizza e gestisce il processo di compilazione
class driver
{
public:
  driver();
  void scan_begin();     // Implementata nello scanner
  void scan_end();       // Implementata nello scanner
  int parse (const std::string& f);

  std::vector<DefAST*> root; // In generale, il programma è una "foresta" di "AST
  yy::location location; // Utilizzata dallo scanner per localizzare i token
  std::string file;      // File sorgente
  std::ostream* outputTarget; // Stream di output per gli AST in Latex
  bool toLatex;          // Abilita la  scrittura su file degli AST in Latex
  std::string opening, closing;
  std::map<char,std::string> *operators;
  
  bool trace_parsing;    // Abilita le tracce di debug nel parser
  bool trace_scanning;   // Abilita le tracce di debug nello scanner
};

#endif // ! DRIVER_HH
