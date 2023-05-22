#include "observer.h"

Observer::Observer():
    subject_(nullptr)
{}

Observer::~Observer()
{
    sleep(3);
    subject_->unregister_(this);
}

void Observer::update()
{
    cout << "update" <<endl;
}

void Observer::observ(Observable * obj)
{
    obj->register_(this);
    subject_ = obj;
}