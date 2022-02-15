#include <iostream>

#include "../inc/exception/NoActionException.hpp"
#include "../inc/state/State.hpp"

bool I1::Action(Symbol* a)
{
    
    if (a->ident == INT)
    {
        this->d4();
    }
    else if(a->ident == OPENPAR)
    {
        this->d5();
    }
    else if(a->ident == END)
    {
        return this->accept(); // accepting
    } 
    else 
    {
        throw NoActionException();
    }
    return false; // not accepting
}

void I1::d4()
{
    // TODO: implement
}

void I1::d5()
{
    // TODO: implement
}

bool I1::accept()
{
    std::cout << "<<< END reached, expression accepted >>>" << std::endl;
    return true;
}



