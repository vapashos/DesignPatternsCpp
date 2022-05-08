#ifndef IOBSERVER_HPP
#define IOBSERVER_HPP

#include <vector>

class ISubject;

class IObserver
{
public:
    IObserver()                          = default;
    virtual ~IObserver()                 = default;
    virtual void Update(const ISubject&) = 0;

private:
    bool _status {true};                 // In case observer is not interested status is going to be false.
};

class ISubject
{
public:
    ISubject()                           = default;
    virtual ~ISubject()                  = default;
    
    void    Attach(IObserver& o);
    void    Notify() const;

    virtual void Print() const          = 0;

private:
    std::vector<IObserver*> _observers;
};


#endif /* IOBSERVER_HPP */
