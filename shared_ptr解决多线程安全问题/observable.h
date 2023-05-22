#pragma once

#include <iostream>
#include <mutex>
#include <thread>
#include <unistd.h>
#include <vector>
#include <algorithm>

class BObserver;

using namespace std;

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