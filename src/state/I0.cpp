#include <iostream>

#include "state/State.hpp"
#include "exception/NoActionException.hpp"

bool I0::Action(Symbol* a)
{
    if(a->ident == OPENPAR)
    {
        d(a, 2);
    }
    else if (a->ident == INT)
    {
        d(a, 3);
    } 
    else if(a->ident == EXPR)
    {
        transition(automaton.states[1]);
    } else {
        throw NoActionException();
    }
    return false; // not accepting
}

void I0::transition(State* state)
{
        // Do the transition of state
    // -> Add state to the stack
    automaton.stateStack.push_back(automaton.states[6]);

    // -> Add symbol to the stack
    automaton.symbolStack.push_back(automaton.symbols[automaton.cursorIndex+1]);
}