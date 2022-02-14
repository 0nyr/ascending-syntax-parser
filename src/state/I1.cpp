#include <iostream>

#include "../../inc/exception/NoActionException.hpp"
#include "../../inc/state/State.hpp"

bool I1::Action(Symbol* a)
{
    
    if (a->ident == INT)
    {
        this->d4(a);
    }
    else if(a->ident == OPENPAR)
    {
        this->d5(a);
    } 
    else 
    {
        throw NoActionException();
    }
}

void I1::d4(Symbol* a)
{
    // TODO
}

void I1::d5(Symbol* a)
{
    // TODO
}