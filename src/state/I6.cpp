#include <iostream>

#include "../inc/exception/NoActionException.hpp"
#include "../inc/state/State.hpp"

bool I6::Action(Symbol* a)
{
    if (a->ident == PLUS)
    {
        this->d4();
    }
    else if(a->ident == MULT)
    {
        this->d5();
    }
    else if(a->ident == CLOSEPAR)
    {
        this->d9();
    }
    else 
    {
        throw NoActionException();
    }
    return false; // not accepting
}

void I6::d4()
{
    // TODO: implement
}

void I6::d5()
{
    // TODO: implement
}

void I6::d9()
{
    // TODO: implement
}