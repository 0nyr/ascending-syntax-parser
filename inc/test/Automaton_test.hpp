#pragma once

#include "Automaton.hpp"

class Automaton_test
{
    public:
        Automaton_test();
        virtual ~Automaton_test();
        int Test_Parsing();
    
    private:
        Automaton* automaton;
};