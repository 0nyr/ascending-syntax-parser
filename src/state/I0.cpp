#include <iostream>

#include "state/State.hpp"
#include "exception/NoActionException.hpp"

bool I0::Action(Symbol* a)
{
    if(a->ident == OPENPAR)
    {
        d2();
    }
    else if (a->ident == INT)
    {
        d3(a);
    } 
    else if(a->ident == EXPR)
    {
        transition(automaton.states[1]);
    } else {
        throw NoActionException();
    }
    return false; // not accepting
}

void I0::d2()
{
    // TODO: implement
}

// We are now at state 0
// d3 means "transition from state 0 to state 3"
// NOTE: Read table for more information on the transition 
void I0::d3(Symbol* a)
{
    // Do the transition of state
    // -> Add state to the stack
    automaton.stateStack.push_back(automaton.states[3]);

    // -> Add symbol to the stack
    automaton.symbolStack.push_back(a);
}

void I0::transition(State* state)
{
    // TODO: implement
}