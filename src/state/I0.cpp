#include <iostream>

#include "state/State.hpp"
#include "exception/NoActionException.hpp"

bool I0::Action(Symbol* a)
{
    if(a->ident == OPENPAR)
    {
        d(a, 2);
    }
    else if (a->ident == INT)
    {
        d(a, 3);
    } 
    else if(a->ident == EXPR)
    {
        transition(a, 1);
    } else {
        throw NoActionException();
    }
    return false; // not accepting
}