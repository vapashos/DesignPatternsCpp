#include <IObserver.hpp>

void ISubject::Attach(IObserver& o)
{
    _observers.push_back(&o);
}

void ISubject::Notify() const
{
    for(auto observer:_observers)
    {
        observer->Update(*this);
    }
}
