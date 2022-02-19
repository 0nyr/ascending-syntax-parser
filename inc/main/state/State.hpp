#pragma once

#include "lexer/Symbol.hpp"
#include "Automaton.hpp" // circular dependency

//class Automaton; // solves circular dependency

// NOTE: dX = shift with transition to state X
// There are 10 states in the automaton

// NOTE: rX = reduce with grammar rule X
// Grammar rules:
// r1) E' -> E
// r2) E -> E + E
// r3) E -> E * E
// r4) E -> ( E )
// r5) E -> val

class State
{
    public:
        State(
            Automaton& automaton
        ) : automaton(automaton) {};
        virtual ~State(){}; 
        virtual ParsingResult Action(Symbol* a)
        { 
            ParsingResult parsingResult;
            parsingResult.isParsingSuccessful = false;
            parsingResult.expressionValue = 0;
            return parsingResult;
        };
        virtual std::string ToString() { return "state";};
    protected:
        Automaton& automaton;
        void d(Symbol* a, int stateNumberX);
        void transition(Symbol* a, int stateNumberX);
};

class I0 : public State
{
    public:
        I0(
            Automaton& automaton
        ) : State(automaton) {};
        ~I0(){};
        ParsingResult Action(Symbol* a);

        std::string ToString() { return "I0";};
};

class I1 : public State
{
    public:
        I1(
            Automaton& automaton
        ) : State(automaton) {};
        ~I1(){};
        ParsingResult Action(Symbol* a);
        
        ParsingResult accept();

        std::string ToString() { return "I1";};
};

class I2 : public State
{
    public:
        I2(
            Automaton& automaton
        ) : State(automaton) {};
        ~I2(){};
        ParsingResult Action(Symbol* a);

        std::string ToString() { return "I2";};
};

class I3 : public State
{
    public:
        I3(
            Automaton& automaton
        ) : State(automaton) {};
        ~I3(){};
        ParsingResult Action(Symbol* a);
        
        void r5();

        std::string ToString() { return "I3";};
};

class I4 : public State
{
    public:
        I4(
            Automaton& automaton
        ) : State(automaton) {};
        ~I4(){};
        ParsingResult Action(Symbol* a);

        std::string ToString() { return "I4";};
};

class I5 : public State
{
    public:
        I5(
            Automaton& automaton
        ) : State(automaton) {};
        ~I5(){};
        ParsingResult Action(Symbol* a);

        std::string ToString() { return "I5";};
};

class I6 : public State
{
    public:
        I6(
            Automaton& automaton
        ) : State(automaton) {};
        ~I6(){};
        ParsingResult Action(Symbol* a);

        std::string ToString() { return "I6";};
};

class I7 : public State
{
    public:
        I7(
            Automaton& automaton
        ) : State(automaton) {};
        ~I7(){};
        ParsingResult Action(Symbol* a);

        void r2();

        std::string ToString() { return "I7";};
};

class I8 : public State
{
    public:
        I8(
            Automaton& automaton
        ) : State(automaton) {};
        ~I8(){};
        ParsingResult Action(Symbol* a);
        
        void r3();

        std::string ToString() { return "I8";};
};

class I9 : public State
{
    public:
        I9(
            Automaton& automaton
        ) : State(automaton) {};
        ~I9(){};
        ParsingResult Action(Symbol* a);
        
        void r4();

        std::string ToString() { return "I9";};
};