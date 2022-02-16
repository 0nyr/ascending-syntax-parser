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
void I3::r5()
{
    // Here, a can be either PLUS, MULT, CLOSEPAR or END 
    // [E -> val. ,+,*,$,)] --- r5) E -> val
    automaton.stateStack.pop_back(); // depile 1 state
    automaton.lookBackCursorIndex(); // look back cursor

    // use pointer magic, convert the symbol in symbols
    // using its pointer stored in the symbolStack
    automaton.symbolStack.back()->ident = EXPR; // convert to EXPR the last symbol of the stack
    automaton.symbolStack.pop_back(); // depile 1 symbole (after conversion)
}
