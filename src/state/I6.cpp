#include <iostream>

#include "../../inc/exception/NoActionException.hpp"
#include "../../inc/state/State.hpp"

bool I6::Action(Symbol* a)
{
    if (a->ident == PLUS)
    {
        this->d4(a);
    }
    else if(a->ident == MULT)
    {
        this->d5(a);
    }
    else if(a->ident == CLOSEPAR)
    {
        this->d9(a);
    }
    else 
    {
        throw NoActionException();
    }
}

void I6::d4(Symbol* a)
{
    // TODO
}

void I6::d5(Symbol* a)
{
    // TODO
}

void I6::d9(Symbol* a)
{
    // TODO
}