#include <iostream>

#include "../inc/state/State.hpp"
#include "../inc/exception/NoActionException.hpp"

bool I0::Action(Symbol* a)
{
    if(a->ident == OPENPAR)
    {
        this->d2();
    }
    else if (a->ident == INT)
    {
        this->d3(a);
    } 
    else if(a->ident == EXPR)
    {
        this->transition(this->automaton.states[1]);
    } else {
        throw NoActionException();
    }
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