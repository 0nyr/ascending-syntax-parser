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
// r4) E -> E ( E )
// r5) E -> val

class State
{
    public:
        State(
            Automaton& automaton
        ) : automaton(automaton) {};
        virtual ~State(){}; 
        virtual bool Action(Symbol* a){ return false; };
        virtual std::string toString() { return "state";};
    protected:
        Automaton& automaton;
};

class I0 : public State
{
    public:
        I0(
            Automaton& automaton
        ) : State(automaton) {};
        ~I0(){};
        bool Action(Symbol* a);

        void d2(Symbol* a);
        void d3(Symbol* a);
        void transition(State* nextState);

        std::string toString() { return "I0";};
};

class I1 : public State
{
    public:
        I1(
            Automaton& automaton
        ) : State(automaton) {};
        ~I1(){};
        bool Action(Symbol* a);
        
        void d4(Symbol* a);
        void d5(Symbol* a);
        bool accept();

        std::string toString() { return "I1";};
};

class I2 : public State
{
    public:
        I2(
            Automaton& automaton
        ) : State(automaton) {};
        ~I2(){};
        bool Action(Symbol* a);
        
        void d2(Symbol* a);
        void d3(Symbol* a);
        void transition(State* nextState);

        std::string toString() { return "I2";};
};

class I3 : public State
{
    public:
        I3(
            Automaton& automaton
        ) : State(automaton) {};
        ~I3(){};
        bool Action(Symbol* a);
        
        void r5(Symbol* a);

        std::string toString() { return "I3";};
};

class I4 : public State
{
    public:
        I4(
            Automaton& automaton
        ) : State(automaton) {};
        ~I4(){};
        bool Action(Symbol* a);
        
        void d2(Symbol* a);
        void d3(Symbol* a);
        void transition(State* nextState);

        std::string toString() { return "I4";};
};

class I5 : public State
{
    public:
        I5(
            Automaton& automaton
        ) : State(automaton) {};
        ~I5(){};
        bool Action(Symbol* a);
        
        void d2(Symbol* a);
        void d3(Symbol* a);
        void transition(State* nextState);

        std::string toString() { return "I5";};
};

class I6 : public State
{
    public:
        I6(
            Automaton& automaton
        ) : State(automaton) {};
        ~I6(){};
        bool Action(Symbol* a);
        
        void d4(Symbol* a);
        void d5(Symbol* a);
        void d9(Symbol* a);

        std::string toString() { return "I6";};
};

class I7 : public State
{
    public:
        I7(
            Automaton& automaton
        ) : State(automaton) {};
        ~I7(){};
        bool Action(Symbol* a);
        
        void r2(Symbol* a);
        void d5(Symbol* a);

        std::string toString() { return "I7";};
};

class I8 : public State
{
    public:
        I8(
            Automaton& automaton
        ) : State(automaton) {};
        ~I8(){};
        bool Action(Symbol* a);
        
        void r3(Symbol* a);

        std::string toString() { return "I8";};
};

class I9 : public State
{
    public:
        I9(
            Automaton& automaton
        ) : State(automaton) {};
        ~I9(){};
        bool Action(Symbol* a);
        
        void r4(Symbol* a);

        std::string toString() { return "I9";};
};