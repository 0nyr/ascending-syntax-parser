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
    // [E -> val. ,+,*,$,)]
    if (a->ident == INT)
    {
        // depile 1 state and convert INT to EXPR
        automaton.stateStack.pop_back();
        a->ident = EXPR;
    } else {
        throw NoRuleException("State I3 only matches [E -> val. ,+,*,$,)] rule.");
    }

} 