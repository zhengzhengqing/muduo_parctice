#include "observer.h"

#if 0 // 未使用智能指针的BObserver
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
#endif

#if 1 // 使用智能指针的BObserver
BObserver::~BObserver()
{ 
    cout <<"delete  Base" <<endl;
    //subject_->unregister_(this);  // 不要次行
}

void BObserver::observ(Observable* obj)
{
    // obj->register_(this);
    // subject_ = obj;
}


void Observer::update()
{
    cout << "update" <<endl;
}

Observer::~Observer()
{
    cout <<"delete Derived " <<endl;
}
#endif