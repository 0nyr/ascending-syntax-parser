#include <iostream>

#include "exception/NoActionException.hpp"
#include "state/State.hpp"

bool I5::Action(Symbol* a)
{
    if (a->ident == INT)
    {
        d2(a);
    }
    else if(a->ident == OPENPAR)
    {
        d3(a);
    }
    else if(a->ident == EXPR)
    {
        transition(automaton.states[8]);
    }
    else 
    {
        throw NoActionException();
    }
    return false; // not accepting
}

void I5::d2(Symbol* a)
{
    // Do the transition of state
    // -> Add state to the stack
    automaton.stateStack.push_back(automaton.states[2]);

    // -> Add symbol to the stack
    automaton.symbolStack.push_back(a);
}

void I5::d3(Symbol* a)
{
    // Do the transition of state
    // -> Add state to the stack
    automaton.stateStack.push_back(automaton.states[5]);

    // -> Add symbol to the stack
    automaton.symbolStack.push_back(a);
}

void I5::transition(State* state)
{
    // TODO
}