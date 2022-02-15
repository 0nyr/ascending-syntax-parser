#include <iostream>

#include "../../inc/exception/NoActionException.hpp"
#include "../../inc/state/State.hpp"

bool I1::Action(Symbol* a)
{
    
    if (a->ident == INT)
    {
        this->d4(a);
    }
    else if(a->ident == OPENPAR)
    {
        this->d5(a);
    } 
    else 
    {
        throw NoActionException();
    }
}

void I1::d4(Symbol* a)
{
    // Do the transition of state
    // -> Add state to the stack
    automaton.stateStack.push_back(automaton.states[4]);

    // -> Add symbol to the stack
    automaton.symbolStack.push_back(a);
}

void I1::d5(Symbol* a)
{
    // Do the transition of state
    // -> Add state to the stack
    automaton.stateStack.push_back(automaton.states[5]);

    // -> Add symbol to the stack
    automaton.symbolStack.push_back(a);
}