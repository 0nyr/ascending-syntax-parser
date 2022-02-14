#include <iostream>

#include "../../inc/exception/NoActionException.hpp"
#include "../../inc/exception/NoRuleException.hpp"
#include "../../inc/state/State.hpp"

bool I7::Action(Symbol* a)
{
    if (
        a->ident == PLUS ||
        a->ident == CLOSEPAR ||
        a->ident == END
        )
    {
        this->r2(a);
    }
    else if(a->ident == MULT)
    {
        this->d5(a);
    }
    else 
    {
        throw NoActionException();
    }
}

void I7::r2(Symbol* a)
{
    // TODO
} 

void I7::d5(Symbol* a)
{
    // TODO
}