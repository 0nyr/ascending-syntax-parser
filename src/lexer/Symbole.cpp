#include <iostream>

#include "../../inc/lexer/Symbol.hpp"

void Symbol::Display() {
   cout<<Labels[ident];
}

void Int::Display() {
   Symbol::Display();
   cout<<"("<<value<<")";
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