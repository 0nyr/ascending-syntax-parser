#pragma once
#include "../lexer/Symbol.hpp"
#include "../Automaton.hpp"
// NOTE: dX = shift with transition to state X
// NOTE: rX = reduce with production X

class State
{
    public:
        State(
            Automaton& automaton
        ) : automaton(automaton) {};
        ~State(){}; 
        bool Action(Symbol* a){};
    
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
};