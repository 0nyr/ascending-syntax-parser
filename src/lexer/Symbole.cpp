#include "inc/lexer/Symbol.hpp"
#include <iostream>

void Symbol::Display() {
   cout<<Labels[ident];
}

void Int::Display() {
   Symbol::Display();
   cout<<"("<<value<<")";
}
