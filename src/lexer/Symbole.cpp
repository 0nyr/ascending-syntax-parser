#include <iostream>

#include "../../inc/lexer/Symbol.hpp"

void Symbol::Display() {
   cout<<Labels[ident];
}

void Int::Display() {
   Symbol::Display();
   cout<<"("<<value<<")";
}
