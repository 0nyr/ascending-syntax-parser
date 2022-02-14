#include <iostream>
#include "inc/state/State.hpp"

bool I0::Action(Symbol* a)
{
    if (a->ident == INT)
    {
        this->d3();
    }
    else if(a->ident == OPENPAR)
    {
        this->d2();
    }
    else if(a->ident == EXPR)
    {
        this->transition(this->automaton.states[1]);
    }
}