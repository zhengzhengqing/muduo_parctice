#pragma once

#include <iostream>
#include <mutex>
#include <thread>
#include <unistd.h>
#include <vector>
#include <algorithm>

class Observer;

using namespace std;

class Observable
{
    private:
        std::vector<Observer*> observers_;

    public:
        void register_(Observer* obj);
        void unregister_(Observer* obj);
        void notify_observers();
};