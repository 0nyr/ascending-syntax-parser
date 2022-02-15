#include <iostream>

#include "../inc/exception/NoActionException.hpp"
#include "../inc/state/State.hpp"

bool I7::Action(Symbol* a)
{
    if (
        a->ident == PLUS ||
        a->ident == CLOSEPAR ||
        a->ident == END
        )
    {
        this->r2();
    }
    else if(a->ident == MULT)
    {
        this->d5();
    }
    else 
    {
        throw NoActionException();
    }
}