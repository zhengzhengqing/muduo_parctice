#include "observer.h"

BObserver::~BObserver()
{
    sleep(3);
    cout <<"delete  Base" <<endl;
    subject_->unregister_(this);
}

void BObserver::observ(Observable* obj)
{
    obj->register_(this);
    subject_ = obj;
}

// void Observer::observ(Observable* obj)
// {
//     obj->register_(this);
//     subject_ = obj;
// }

void Observer::update()
{
    cout << "update" <<endl;
}

Observer::~Observer()
{
    sleep(3);
    cout <<"delete Derived " <<endl;
}