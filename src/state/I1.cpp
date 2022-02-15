#include <iostream>

#include "exception/NoActionException.hpp"
#include "state/State.hpp"

bool I1::Action(Symbol* a)
{
    
    if (a->ident == INT)
    {
        d4(a);
    }
    else if(a->ident == OPENPAR)
    {
        d5(a);
    }
    else if(a->ident == END)
    {
        return accept(); // accepting
    } 
    else 
    {
        throw NoActionException();
    }
    return false; // not accepting
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

bool I1::accept()
{
    std::cout << "<<< END reached, expression accepted >>>" << std::endl;
    return true;
}