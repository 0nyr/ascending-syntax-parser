#include <iostream>

#include "exception/NoActionException.hpp"
#include "state/State.hpp"

bool I4::Action(Symbol* a)
{
    if (a->ident == INT)
    {
        d2();
    }
    else if(a->ident == OPENPAR)
    {
        d3();
    }
    else if(a->ident == EXPR)
    {
        transition(automaton.states[7]);
    }
    else 
    {
        throw NoActionException();
    }
    return false; // not accepting
}

void I4::d2()
{
    // TODO: implement
}

void I4::d3()
{
    // TODO: implement
}

void I4::transition(State* state)
{
    // TODO: implement
}