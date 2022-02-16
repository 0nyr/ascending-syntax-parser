#include <iostream>

#include "state/State.hpp"
#include "exception/NoActionException.hpp"

void State::d(Symbol* a, int stateNumberX)
{
    // Do the transition of state
    // -> Add state to the stack
    automaton.stateStack.push_back(automaton.states[stateNumberX]);

    // -> Add symbol to the stack
    automaton.symbolStack.push_back(a);
}