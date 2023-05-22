#pragma once 

#include <iostream>
#include <mutex>
#include <thread>
#include <unistd.h>

#include "observable.h" 

using namespace std;

class Observable;

class Observer
{
    private:
        Observable* subject_;
    public:
        Observer();
        ~Observer();
        void update();
        void observ(Observable * obj);
};