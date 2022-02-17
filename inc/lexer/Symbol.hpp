#pragma once

#include <string>
using namespace std;

enum Identifier { OPENPAR, CLOSEPAR, PLUS, MULT, INT, END, ERREUR, EXPR };

const string Labels[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "END", "ERREUR", "EXPR" };

class Symbol {
   public:
      Symbol(Identifier i) : ident(i) {  }
      virtual ~Symbol() { }
      virtual void Display();
      virtual int getValue();
      virtual string ToString();
      Identifier ident;
};

class Int : public Symbol {
   public:
      Int(int v) : Symbol(INT), value(v) { }
      ~Int() { }
      virtual void Display();
      int getValue();
      string ToString();
      operator int() const { return value; } // cast entier

   protected:
      int value;
};

class Expr : public Symbol {
   public:
      Expr(int i) : Symbol(EXPR), value(i) {}
      ~Expr() {}
      virtual void Display();
      int getValue();
      inline void setValue(int i) { value = i; }

   protected:
      int value;
};

