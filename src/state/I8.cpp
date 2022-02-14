#include <iostream>

#include "../../inc/exception/NoActionException.hpp"
#include "../../inc/state/State.hpp"

bool I8::Action(Symbol* a)
{
    if (
        a->ident == PLUS ||
        a->ident == MULT ||
        a->ident == CLOSEPAR ||
        a->ident == END
        )
    {
        this->r3(a);
    }
    else 
    {
        throw NoActionException();
    }
}

void I8::r3(Symbol* a)
{
    // TODO
} 