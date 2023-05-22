#pragma once 

#include <iostream>
#include <mutex>
#include <thread>
#include <unistd.h>

#include "observable.h" 

using namespace std;

class Observable;

class BObserver
{
    public:
        BObserver() = default;
        virtual ~BObserver();

    public:
        virtual void update() = 0;
        void observ(Observable * obj);
    
    public:
        Observable* subject_;
};


class Observer : public BObserver
{   
    public:
        Observer() = default;
        ~Observer() ;
        void update() override; //  让编译器帮忙排查覆盖规则
        //void observ(Observable * obj);
};