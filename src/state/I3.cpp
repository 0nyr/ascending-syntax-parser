#include <iostream>

#include "exception/NoActionException.hpp"
#include "state/State.hpp"

bool I3::Action(Symbol* a)
{
    if (
        a->ident == PLUS ||
        a->ident == MULT ||
        a->ident == CLOSEPAR ||
        a->ident == END
        )
    {
        r5();
    }
    else 
    {
        throw NoActionException();
    }
    return false; // not accepting
}

// We are at state I3
// NOTE: rX = reduce with production X
// r5) E -> val
void I3::r5()
{
    // depile state
    automaton.stateStack.pop_back(); // depile 1 state
    automaton.lookBackCursorIndex(1); // look back cursor (1 state = 1 symbol removed)

    // use pointer magic, convert the symbol in symbols vector
    // using its pointer stored in the symbolStack
    automaton.symbolStack.back()->ident = EXPR; // convert to EXPR the last symbol of the stack
    automaton.symbolStack.pop_back(); // depile 1 symbole (after conversion)
}
