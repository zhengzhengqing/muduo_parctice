#include "observer.h"

void Observable::register_(BObserver* obj)
{
    std::unique_lock<std::mutex> lock(mutex_);
    observers_.push_back(obj);
}

void Observable::unregister_(BObserver* obj)
{
    auto iter = std::find(observers_.begin(), observers_.end(), obj);
    
    if(iter == observers_.end())
    {
        cout <<"not found " <<endl;
    }
    else
    {   
        std::unique_lock<std::mutex> lock(mutex_);
        observers_.erase(iter);
    }
}

void Observable::notify_observers()
{
    std::unique_lock<std::mutex> lock(mutex_);
    for(BObserver* iter : observers_)
    {
        iter->update();
    }
}
