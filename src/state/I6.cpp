#include <iostream>

#include "exception/NoActionException.hpp"
#include "state/State.hpp"

bool I6::Action(Symbol* a)
{
    if (a->ident == PLUS)
    {
        d4(a);
    }
    else if(a->ident == MULT)
    {
        d5(a);
    }
    else if(a->ident == CLOSEPAR)
    {
        d9(a);
    }
    else 
    {
        throw NoActionException();
    }
    return false; // not accepting
}

void I6::d4(Symbol* a)
{
    // Do the transition of state
    // -> Add state to the stack
    automaton.stateStack.push_back(automaton.states[4]);

    // -> Add symbol to the stack
    automaton.symbolStack.push_back(a);
}

void I6::d5(Symbol* a)
{
    // Do the transition of state
    // -> Add state to the stack
    automaton.stateStack.push_back(automaton.states[5]);

    // -> Add symbol to the stack
    automaton.symbolStack.push_back(a);
}

void I6::d9(Symbol* a)
{
    // Do the transition of state
    // -> Add state to the stack
    automaton.stateStack.push_back(automaton.states[9]);

    // -> Add symbol to the stack
    automaton.symbolStack.push_back(a);
}