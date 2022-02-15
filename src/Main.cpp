#include <vector>
#include <iostream>


#include "state/State.hpp"
#include "lexer/Symbol.hpp"
#include "Automaton.hpp"

int main()
{

    // declare expression to be recognized
    string inputExpression("(1+34)*123");

    // check if the expression is valid
    Automaton* automaton = new Automaton();
    automaton->init(
        inputExpression, *automaton
    );
    bool isExpressionValid = automaton->Parsing();
    if (isExpressionValid)
    {
        std::cout<<"Expression is valid"<<std::endl;
    }
    else
    {
        std::cout<<"Expression is invalid"<<std::endl;
    }

    // free memory
    delete automaton;
    return 0;
}


