#include <iostream>

#include "../../inc/exception/NoActionException.hpp"
#include "../../inc/state/State.hpp"

bool I4::Action(Symbol* a)
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
        this->transition(this->automaton.states[7]);
    }
    else 
    {
        throw NoActionException();
    }
}

void I4::d2(Symbol* a)
{
    // Do the transition of state
    // -> Add state to the stack
    automaton.stateStack.push_back(automaton.states[2]);

    // -> Add symbol to the stack
    automaton.symbolStack.push_back(a);
}

void I4::d3(Symbol* a)
{
    // Do the transition of state
    // -> Add state to the stack
    automaton.stateStack.push_back(automaton.states[3]);

    // -> Add symbol to the stack
    automaton.symbolStack.push_back(a);
}

void I4::transition(State* s)
{
    // TODO
}