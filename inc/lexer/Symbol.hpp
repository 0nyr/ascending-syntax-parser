#pragma once

#include <string>
using namespace std;

enum Identifier { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR, EXPR };

const string Labels[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR", "EXPR" };

class Symbol {
   public:
      Symbol(Identifier i) : ident(i) {  }
      virtual ~Symbol() { }
      virtual void Display();
      Identifier ident;
};

class Int : public Symbol {
   public:
      Int(int v) : Symbol(INT), value(v) { }
      ~Int() { }
      virtual void Display();
      
      operator int() const { return value; } // cast entier

   protected:
      int value;
};

class Expr : public Symbol {
   public:
      Expr(int i) : Symbol(EXPR) {}
      ~Expr() {}
      virtual void Display();
   protected:
};

