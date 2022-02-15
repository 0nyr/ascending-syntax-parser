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
    return false; // not accepting
}

void I7::d5()
{
    //  TODO: implement
}

void I7::r2()
{
    // TODO: implement
}