#include <iostream>
#include <IObserver.hpp>




class StateMachine: public ISubject
{

public:
    
    enum States
    {
        IDLE,
        RUNNING,
        COMPLETED,
        ALL_STATES
    };

    StateMachine()              = default;
    virtual ~StateMachine()     = default;
    virtual void Print() const override;
    void SetState(const States& st);

private:
    const char* _state_str[ALL_STATES] = {"IDLE","RUNNING","COMPLETED"};
    States      _state {IDLE};
};

void StateMachine::SetState(const States& st) 
{ 
    _state = st; 
    Notify();
}

void StateMachine::Print() const
{
    std::cout<<"STATE : "<<_state_str[_state]<<std::endl;
}


class StateObserver: public IObserver
{
public:
    
    StateObserver() = default;
    
    virtual ~StateObserver() = default;
    virtual void Update(const ISubject& s) override;
    
};

void StateObserver::Update(const ISubject& s)
{
    std::cout<<"OBSERVER GET STATE MACHINE STATUS:";
    s.Print();
}


int main(void)
{
    std::cout<<"Implementation of Observer Pattern"<<std::endl;
    
    StateMachine    myMachine;
    StateObserver   observer;
    
    myMachine.Attach(observer);
    myMachine.SetState(StateMachine::RUNNING);
    myMachine.SetState(StateMachine::IDLE);
    myMachine.SetState(StateMachine::COMPLETED);


}
