#include <iostream>

#include "../../inc/exception/NoActionException.hpp"
#include "../../inc/exception/NoRuleException.hpp"
#include "../../inc/state/State.hpp"

bool I3::Action(Symbol* a)
{
    if (
        a->ident == PLUS ||
        a->ident == MULT ||
        a->ident == CLOSEPAR ||
        a->ident == END
        )
    {
        this->r5(a);
    }
    else 
    {
        throw NoActionException();
    }
}

// We are at state I3
// NOTE: rX = reduce with production X
void I3::r5(Symbol* a)
{
    // Here, a can be either PLUS, MULT, CLOSEPAR or END 
    // [E -> val. ,+,*,$,)] --- r5) E -> val
    automaton.stateStack.pop_back(); // depile 1 state
    automaton.cursorIndex--; // look back 
    automaton.symbolStack.back()->ident = EXPR; // convert to EXPR the last symbol of the stack
} 
