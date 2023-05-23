#pragma once

#include <iostream>
#include <mutex>
#include <thread>
#include <unistd.h>
#include <vector>
#include <algorithm>
#include <memory>

class BObserver;

using namespace std;

#if 0 // 未使用智能指针的Observable
class Observable
{
    private:
        std::mutex mutex_;
        std::vector<BObserver*> observers_;

    public:
        void register_(BObserver* obj);
        void unregister_(BObserver* obj);
        void notify_observers();
};

#endif

#if 1 // 使用了智能指针的Observable
class Observable
{
    public:
        Observable() = default;
        ~Observable() = default;
        void notify_observers();
        void register_(weak_ptr<BObserver> w_ptr);
    
    public:
        std::mutex mutex_;
        std::vector<weak_ptr<BObserver>> observers_;
};

#endif