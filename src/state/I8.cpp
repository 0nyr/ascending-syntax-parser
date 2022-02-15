#include <iostream>

#include "exception/NoActionException.hpp"
#include "state/State.hpp"

bool I8::Action(Symbol* a)
{
    if (
        a->ident == PLUS ||
        a->ident == MULT ||
        a->ident == CLOSEPAR ||
        a->ident == END
        )
    {
        r3();
    }
    else 
    {
        throw NoActionException();
    }
    return false; // not accepting
}

void I8::r3()
{
    // TODO: implement
}

