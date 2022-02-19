#include <iostream>

#include "exception/NoActionException.hpp"
#include "exception/WrongSymbolException.hpp"
#include "state/State.hpp"
#include "util/util.hpp"

bool I9::Action(Symbol* a)
{
    if (
        a->ident == PLUS ||
        a->ident == MULT ||
        a->ident == CLOSEPAR ||
        a->ident == END
        )
    {
        r4();
    }
    else 
    {
        throw NoActionException();
    }
    return false; // not accepting
}

// r4) E -> ( E )
void I9::r4()
{   
    // check ( E )
    std::size_t symbolStackSize = automaton.symbolStack.size();
    if (
        automaton.symbolStack[symbolStackSize - 3]->ident == OPENPAR &&
        automaton.symbolStack[symbolStackSize - 2]->ident == EXPR &&
        automaton.symbolStack[symbolStackSize - 1]->ident == CLOSEPAR
    ) {
        // WARN: We will keep the middle "E" with its value
        // free memory of "(" and ")" in the symbols vector
        delete automaton.symbols[symbolStackSize - 1];
        delete automaton.symbols[symbolStackSize - 3];

        // then erase the "(" and ")" from the symbols vector
        // warn: THE ORDER IS IMPORTANT
        // Erasing changes the position of the following elements
        // So start from the most tailing element
        automaton.symbols.erase(
            automaton.symbols.begin() + symbolStackSize - 1 // most tailing element
        );
        automaton.symbols.erase(
            automaton.symbols.begin() + symbolStackSize - 3
        );
        
        // erase "(", "E" and ")" from symbolStack vector, 
        automaton.symbolStack.pop_back();
        automaton.symbolStack.pop_back();
        automaton.symbolStack.pop_back();

        // depile 3 states and look back cursor
        automaton.stateStack.pop_back(); 
        automaton.stateStack.pop_back(); 
        automaton.stateStack.pop_back(); 
        automaton.lookBackCursorIndex(3); // look back cursor
    }
    else
    {
        throw WrongSymbolException("Wrong symbols, expected ( E ).");
    }
}
