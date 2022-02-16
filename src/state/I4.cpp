#include <iostream>

#include "exception/NoActionException.hpp"
#include "state/State.hpp"

bool I4::Action(Symbol* a)
{
    if (a->ident == INT)
    {
        d(a, 2);
    }
    else if(a->ident == OPENPAR)
    {
        d(a, 3);
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

void I4::transition(State* state)
{
    // TODO: implement
}