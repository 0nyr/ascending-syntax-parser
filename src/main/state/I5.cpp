#include <iostream>

#include "exception/NoActionException.hpp"
#include "state/State.hpp"

ParsingResult I5::Action(Symbol* a)
{
    if (a->ident == INT)
    {
        d(a, 3);
    }
    else if(a->ident == OPENPAR)
    {
        d(a, 2);
    }
    else if(a->ident == EXPR)
    {
        transition(a, 8);
    }
    else 
    {
        throw NoActionException();
    }
    return ParsingResult(); // not accepting
}