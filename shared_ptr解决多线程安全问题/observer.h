#pragma once 

#include <iostream>
#include <mutex>
#include <thread>
#include <unistd.h>

#include "observable.h" 

using namespace std;

class Observable;

#if 0 // 未使用智能指针的 BObserver
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

#endif

#if 1
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
#endif

