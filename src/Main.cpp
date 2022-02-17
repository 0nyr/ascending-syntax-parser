#include <vector>
#include <iostream>

#include "state/State.hpp"
#include "lexer/Symbol.hpp"
#include "Automaton.hpp"

#include "util/util.hpp"


int main(int argc, char** argv)
{
    // declare default expression to be recognized
    std::string inputExpression("(1+34)*123");

    cout << "You have entered " << argc
        << " arguments:" << "\n";
  
    for (int i = 0; i < argc; ++i)
    {
        cout << "argv[" << i << "]: " << argv[i] << "\n";
    }

    if (argc > 1)
    {
        inputExpression = argv[1];
    }
    
    std::vector<int> testvect;
    testvect.push_back(1);
    std::cout << vectorToString<int>(testvect) << std::endl;
    testvect.pop_back();
    std::cout << vectorToString<int>(testvect) << std::endl;

    // check if the expression is valid
    Automaton automaton = Automaton(
        inputExpression
    );
    bool isExpressionValid = automaton.Parsing();
    if (isExpressionValid)
    {
        std::cout<<"Expression is valid"<<std::endl;
    }
    else
    {
        std::cout<<"Expression is invalid"<<std::endl;
    }

    return 0;
}


