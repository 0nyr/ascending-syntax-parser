#include <iostream>

#include "lexer/Symbol.hpp"

void Symbol::Display() {
   std::cout<<Labels[ident];
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