#include "lexer/Symbol.hpp"
#include <iostream>

void Symbol::Display() {
   std::cout<<Labels[ident];
}

void Int::Display() {
   Symbol::Display();
   std::cout<<"("<<value<<")";
}
