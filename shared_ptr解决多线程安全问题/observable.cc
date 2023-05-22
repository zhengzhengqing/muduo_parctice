#include "observer.h"

void Observable::register_(Observer* obj)
{
    observers_.push_back(obj);
}

void Observable::unregister_(Observer* obj)
{
    remove(observers_.begin(), observers_.end(), obj);
}

void Observable::notify_observers()
{
    for(Observer* iter : observers_)
    {
        iter->update();
    }
}
