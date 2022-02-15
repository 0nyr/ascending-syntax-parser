#include <iostream>

#include "../../inc/exception/NoActionException.hpp"
#include "../../inc/state/State.hpp"

bool I2::Action(Symbol* a)
{
    if (a->ident == OPENPAR)
    {
        this->d2(a);
    }
    else if(a->ident == INT)
    {
        this->d3(a);
    }
    else if(a->ident == EXPR)
    {
        this->transition(this->automaton.states[6]);
    }
    else 
    {
        throw NoActionException();
    }
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