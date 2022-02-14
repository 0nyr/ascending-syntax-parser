#include <iostream>

#include "inc/exception/NoActionException.hpp"
#include "inc/state/State.hpp"

bool I1::Action(Symbol* a)
{
    
    if (a->ident == INT)
    {
        this->d4();
    }
    else if(a->ident == OPENPAR)
    {
        this->d5();
    } 
    else 
    {
        throw NoActionException();
    }
}