#include <iostream>

#include "exception/NoActionException.hpp"
#include "state/State.hpp"

bool I9::Action(Symbol* a)
{
    if (
        a->ident == PLUS ||
        a->ident == MULT ||
        a->ident == CLOSEPAR ||
        a->ident == END
        )
    {
        r4();
    }
    else 
    {
        throw NoActionException();
    }
    return false; // not accepting
}

void I9::r4()
{
    // TODO: implement
}