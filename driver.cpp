#include <fstream>
#include "driver.hpp"
#include "parser.hpp"

driver::driver(): trace_parsing(false), trace_scanning(false), toLatex(false),
                  opening("["), closing("]") {};
extern driver drv;

int driver::parse (const std::string &f)
{
  file = f;
  location.initialize(&file);
  scan_begin();
  yy::parser parser(*this);
  parser.set_debug_level(trace_parsing);
  int res = parser.parse();
  scan_end();
  return res;
}

NumberExprAST::NumberExprAST(int Val): Val(Val) {};
void NumberExprAST::visit() {
  *drv.outputTarget << "[" << Val << "]";
};
lexval NumberExprAST::getLexVal() const {
  lexval lval = Val;
  return lval;
};


YieldExprAST::YieldExprAST(ExprAST* Expr): Expr(Expr) {}

void YieldExprAST::visit() {
  *drv.outputTarget << "[yield ";  
  Expr->visit();                   
  *drv.outputTarget << "]";
}

lexval YieldExprAST::getLexVal() const {
  return Expr->getLexVal();  
}


AwaitExprAST::AwaitExprAST(ExprAST* expr)
    : expr(std::move(expr)) {}
void AwaitExprAST::visit() {
  *drv.outputTarget << "[await ";  
  expr->visit();                   
  *drv.outputTarget << "]";
}
lexval AwaitExprAST::getLexVal() const {
  return expr->getLexVal();  
}

// Implementazione della classe SetExprAST
SetExprAST::SetExprAST(std::vector<std::pair<std::string, ExprAST*>> Assignments): Assignments(std::move(Assignments)) {}
void SetExprAST::visit() {
    *drv.outputTarget << "[set ";  // Output per rappresentare l'inizio del set

    for (const auto& assignment : Assignments) {
        *drv.outputTarget << assignment.first << " = ";  // Identificatore dell'assegnamento
        assignment.second->visit();  // Visita l'espressione associata all'assegnamento
        *drv.outputTarget << "; ";  // Aggiungi separatore ";"
    }

    *drv.outputTarget << "]";
}



BlockExprAST::BlockExprAST(std::vector<std::pair<std::string, ExprAST*>> Assignments): Assignments(std::move(Assignments)) {}
void BlockExprAST::visit() {
    *drv.outputTarget << "[block ";  // Output per rappresentare l'inizio del block

    for (const auto& assignment : Assignments) {
        *drv.outputTarget << assignment.first << " = ";  // Identificatore dell'assegnamento
        assignment.second->visit();  // Visita l'espressione associata all'assegnamento
        *drv.outputTarget << "; ";  // Aggiungi separatore ";"
    }

    *drv.outputTarget << "]";
}
// Restituisce sempre 0 come valore dell'espressione block
lexval BlockExprAST::getLexVal() const {
  return 0;
}



IdeExprAST::IdeExprAST(std::string &Name): Name(Name) {};
lexval IdeExprAST::getLexVal() const {
  lexval lval = Name;
  return lval;
};
void IdeExprAST::visit() {
  *drv.outputTarget << drv.opening << Name << drv.closing;
};

BinaryExprAST::BinaryExprAST(std::string Op, ExprAST* LHS, ExprAST* RHS): Op(Op), LHS(LHS), RHS(RHS) {};

void BinaryExprAST::visit() {
  if (Op == "=") {
    // Verifica che il LHS sia un identificatore
    if (dynamic_cast<IdeExprAST*>(LHS) == nullptr) {
      // Se il lato sinistro non è un identificatore, non è un'assegnazione valida
      *drv.outputTarget << "Error: LHS of '=' must be an identifier!";
      return;
    }

    *drv.outputTarget << "[= ";
    LHS->visit();  
    RHS->visit();  
    *drv.outputTarget << "]";
  } else {
    *drv.outputTarget << drv.opening << Op << " ";
    LHS->visit();
    RHS->visit();
    *drv.outputTarget << drv.closing;
  }
};

UnaryExprAST::UnaryExprAST(std::string Op, ExprAST* RHS): Op(Op), RHS(RHS) {};
void UnaryExprAST::visit() {
  *drv.outputTarget << drv.opening << Op;
  if (drv.toLatex)
     *drv.outputTarget << "$ ";
  else
     *drv.outputTarget << " ";
  RHS->visit();
  *drv.outputTarget << "]";
};

CallExprAST::CallExprAST(std::string Callee, std::vector<ExprAST*> Args): Callee(Callee), 
                         Args(std::move(Args)) {};
lexval CallExprAST::getLexVal() const {
  lexval lval = Callee;
  return lval;
};
void CallExprAST::visit() {
  *drv.outputTarget << drv.opening << Callee;
    if (drv.toLatex)
     *drv.outputTarget << "$ ";
  else
     *drv.outputTarget << " ";
  for (ExprAST* arg : Args) {
    arg->visit();
  };
  *drv.outputTarget << "]";
};

// Costruttore della classe ForExprAST
ForExprAST::ForExprAST(const std::string var, ExprAST* range, 
                       const std::vector<std::string> usingVars, ExprAST* body)
    : var(var), range(range), usingVars(usingVars), body(body) {}

// Metodo visit per stampare la rappresentazione del nodo
void ForExprAST::visit() {
    *drv.outputTarget << "[for " << var << " in ";
    range->visit();
    if (!usingVars.empty()) {
        *drv.outputTarget << " using [";
        for (const auto& id : usingVars) {
            *drv.outputTarget << id << " ";
        }
        *drv.outputTarget << "]";
    }
    *drv.outputTarget << " do ";
    body->visit();
    *drv.outputTarget << " end]";
}

// Metodo per ottenere il valore lessicale del nodo
lexval ForExprAST::getLexVal() const {
    return NONE;  // Non restituisce un valore specifico
}



IfExprAST::IfExprAST(std::vector<std::pair<ExprAST*, ExprAST*>> IfThenSeq):
  IfThenSeq(std::move(IfThenSeq)) {};
void IfExprAST::visit() {
  *drv.outputTarget << "[if ";
  for (unsigned i=0, e=IfThenSeq.size(); i<e; i++) {
     *drv.outputTarget << "[alt ";
     IfThenSeq[i].first->visit();
     IfThenSeq[i].second->visit();
     *drv.outputTarget << "]";
  }
  *drv.outputTarget << "]";
};
  
LetExprAST::LetExprAST(std::vector<std::pair<std::string, ExprAST*>> Bindings, ExprAST* Body):
  Bindings(std::move(Bindings)), Body(Body) {};
void LetExprAST::visit() {
  *drv.outputTarget << "[let [bindings ";
  for (unsigned i=0, e=Bindings.size(); i<e; i++) {
    *drv.outputTarget << "[= " << drv.opening << Bindings[i].first << drv.closing;
    Bindings[i].second->visit();
    *drv.outputTarget << "]";
  };
  *drv.outputTarget << "][in ";
  Body->visit();
  *drv.outputTarget << "]]";
}; 

PrototypeAST::PrototypeAST(std::string Name, std::vector<std::string> Params):
                           Name(Name), Params(std::move(Params)) {External=false;};
lexval PrototypeAST::getLexVal() const {
  lexval lval = Name;
  return lval;
};
void PrototypeAST::setext() { External = true; };
const std::vector<std::string>& PrototypeAST::getParams() const {
  return Params;
};
void PrototypeAST::visit() {
  if (External) *drv.outputTarget << "[extern ";
  *drv.outputTarget << drv.opening << Name << drv.closing << "[params ";
  for (auto it=Params.begin(); it!=Params.end(); ++it) {
    *drv.outputTarget << drv.opening << *it << drv.closing;
  };
  *drv.outputTarget << "]";
  if (External) *drv.outputTarget << "]";
};
int PrototypeAST::paramssize() {
  return Params.size();
};

FunctionAST::FunctionAST(PrototypeAST* Proto, ExprAST* Body): Proto(Proto), Body(Body) {};
void FunctionAST::visit() {
  *drv.outputTarget << "[function ";
  Proto->visit();
  Body->visit();
  *drv.outputTarget << "]";
};
int FunctionAST::nparams() {
  return Proto->paramssize();
};
