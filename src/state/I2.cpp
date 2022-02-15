#include <iostream>

#include "exception/NoActionException.hpp"
#include "state/State.hpp"

bool I2::Action(Symbol* a)
{
    if (a->ident == OPENPAR)
    {
        d2(a);
    }
    else if(a->ident == INT)
    {
        d3(a);
    }
    else if(a->ident == EXPR)
    {
        transition(automaton.states[6]);
    }
    else 
    {
        throw NoActionException();
    }
    return false; // not accepting
}

void I2::d2(Symbol* a)
{
    // Do the transition of state
    // -> Add state to the stack
    automaton.stateStack.push_back(automaton.states[2]);

    // -> Add symbol to the stack
    automaton.symbolStack.push_back(automaton.symbols[automaton.cursorIndex+1]);
}

void I2::d3(Symbol* a)
{
    // Do the transition of state
    // -> Add state to the stack
    automaton.stateStack.push_back(automaton.states[3]);

    // -> Add symbol to the stack
    automaton.symbolStack.push_back(automaton.symbols[automaton.cursorIndex+1]);
}

void I2::transition(State* s)
{
    // Do the transition of state
    // -> Add state to the stack
    automaton.stateStack.push_back(automaton.states[6]);

    // -> Add symbol to the stack
    automaton.symbolStack.push_back(automaton.symbols[automaton.cursorIndex+1]);
}