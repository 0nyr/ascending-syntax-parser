#include <iostream>

#include "exception/NoActionException.hpp"
#include "exception/WrongSymbolException.hpp"
#include "state/State.hpp"

ParsingResult I8::Action(Symbol* a)
{
    if (
        a->ident == PLUS ||
        a->ident == MULT ||
        a->ident == CLOSEPAR ||
        a->ident == END
        )
    {
        r3();
    }
    else 
    {
        throw NoActionException();
    }
    return ParsingResult(); // not accepting
}

// r3) E -> E * E
void I8::r3()
{   
    // check E * E
    std::size_t symbolStackSize = automaton.symbolStack.size();
    if (
        automaton.symbolStack[symbolStackSize - 3]->ident == EXPR &&
        automaton.symbolStack[symbolStackSize - 2]->ident == MULT &&
        automaton.symbolStack[symbolStackSize - 1]->ident == EXPR
    ) {
        Expr* exprLeft = (Expr*)automaton.symbolStack[symbolStackSize - 3];
        Expr* exprRight = (Expr*)automaton.symbolStack[symbolStackSize - 1];
        exprLeft->setValue(exprLeft->getValue() * exprRight->getValue());

        // WARN: We will keep the left "E" with the new value
        // free memory of "*" and right "E" in the symbols vector
        delete automaton.symbols[symbolStackSize - 2];
        delete automaton.symbols[symbolStackSize - 1];

        // then erase the "*" and "E" from the symbols vector
        automaton.symbols.erase(
            automaton.symbols.begin() + symbolStackSize - 2,
            automaton.symbols.begin() + symbolStackSize
        );

        // erase left "E", "*" and right "E" from symbolStack vector, 
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
        throw WrongSymbolException("Wrong symbols, expected E * E.");
    }
}
