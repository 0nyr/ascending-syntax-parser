#include <iostream>

#include "../../inc/lexer/Symbol.hpp"

void Symbol::Display() {
   std::cout<<Labels[ident];
}

void Int::Display() {
   Symbol::Display();
   std::cout<<"("<<value<<")";
}
