#include "observer.h"

#if 0 // // 未使用智能指针的 Observable
void Observable::register_(BObserver* obj)
{
    //std::unique_lock<std::mutex> lock(mutex_);
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
        //std::unique_lock<std::mutex> lock(mutex_);
        observers_.erase(iter);
    }
}

void Observable::notify_observers()
{
    //std::unique_lock<std::mutex> lock(mutex_);
    for(BObserver* iter : observers_)
    {
        iter->update();
    }
}

#endif

#if 1 // 使用智能指针的Observable
void Observable::register_(weak_ptr<BObserver> w_ptr)
{
    std::unique_lock<std::mutex> lock(mutex_);
    cout <<"got mutex" <<endl;
    observers_.push_back(w_ptr);
}

void Observable::notify_observers()
{
    std::unique_lock<std::mutex> lock(mutex_);
    auto it = observers_.begin();
    while(it != observers_.end())
    {
        shared_ptr<BObserver> obj(it->lock());
        if(obj)
        {
            obj->update();
            ++it;
        }
        else
        {
            cout <<"该对象已析构"<<endl;
            observers_.erase(it);
        }
    }
}

#endif