#include <iostream>

#include "../inc/exception/NoActionException.hpp"
#include "../inc/state/State.hpp"

bool I2::Action(Symbol* a)
{
    if (a->ident == INT)
    {
        this->d2();
    }
    else if(a->ident == OPENPAR)
    {
        this->d3();
    }
    else if(a->ident == EXPR)
    {
        this->transition(this->automaton.states[6]);
    }
    else 
    {
        throw NoActionException();
    }
    return false; // not accepting
}

void I2::d2()
{
    // TODO: implement
}

void I2::d3()
{
    // TODO: implement
}

void I2::transition(State* state)
{
    // TODO: implement
}