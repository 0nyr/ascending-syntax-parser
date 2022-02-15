#include <iostream>

#include "lexer/Symbol.hpp"

string Symbol::ToString()
{
   return Labels[ident];
}

void Symbol::Display() {
   std::cout << ToString() << std::endl;
}

string Int::ToString()
{
   return Labels[ident] + "(" + std::to_string(value) + ")";
}

void Int::Display() {
   Symbol::Display();
   std::cout<<"("<<value<<")";
}

int Symbol::getValue(){
   return -1;
}

int Int::getValue(){
   return value;
}

int Expr::getValue(){
   return value;
}