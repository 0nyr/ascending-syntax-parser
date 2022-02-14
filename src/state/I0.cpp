#include <iostream>

#include "../../inc/exception/NoActionException.hpp"
#include "../../inc/state/State.hpp"

bool I0::Action(Symbol* a)
{
    Symbol* a = automaton.symbolStack.back();
    if(a->ident == OPENPAR)
    {
        this->d2(a);
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
// d2 means "transition from state 0 to state 2"
// NOTE: Read table for more information on the transition 
void I0::d2(Symbol* a)
{
    // Do the transition of state
    // -> Add state to the stack
    automaton.stateStack.push_back(automaton.states[2]);

    // -> Add symbol to the stack
    automaton.symbolStack.push_back(a);
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