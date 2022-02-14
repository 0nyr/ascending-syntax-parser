#include <iostream>

#include "../../inc/exception/NoActionException.hpp"
#include "../../inc/state/State.hpp"

bool I9::Action(Symbol* a)
{
    if (
        a->ident == PLUS ||
        a->ident == MULT ||
        a->ident == CLOSEPAR ||
        a->ident == END
        )
    {
        this->r4(a);
    }
    else 
    {
        throw NoActionException();
    }
}

void I9::r4(Symbol* a)
{
    // TODO
} 