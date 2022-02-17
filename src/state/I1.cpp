#include <iostream>

#include "lexer/Symbol.hpp"
#include "exception/NoActionException.hpp"
#include "state/State.hpp"

bool I1::Action(Symbol* a)
{
    
    if (a->ident == PLUS)
    {
        d(a, 4);
    }
    else if(a->ident == MULT)
    {
        d(a, 5);
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

// r1) E' -> E
bool I1::accept()
{
    std::cout << "<<< END reached, expression accepted >>>" << std::endl;

    // if the last element in the symbolStack is the evaluated expression
    Expr* finalExpr = (Expr*)automaton.symbolStack.back();
    if(finalExpr->ident == EXPR)
    {
        std::cout << "<<< Expression value: " << finalExpr->getValue() << " >>>" << std::endl;
    }
    return true;
}