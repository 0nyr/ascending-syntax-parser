#include <iostream>

#include "../../inc/exception/NoActionException.hpp"
#include "../../inc/state/State.hpp"

bool I5::Action(Symbol* a)
{
    if (a->ident == INT)
    {
        this->d2(a);
    }
    else if(a->ident == OPENPAR)
    {
        this->d3(a);
    }
    else if(a->ident == EXPR)
    {
        this->transition(this->automaton.states[8]);
    }
    else 
    {
        throw NoActionException();
    }
}

void I5::d2(Symbol* a)
{
    // TODO
}

void I5::d3(Symbol* a)
{
    // TODO
}

void I5::transition(State* s)
{
    // TODO
}