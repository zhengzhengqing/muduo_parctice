#pragma once

#include <iostream>
#include <mutex>
#include <thread>
#include <unistd.h>
#include <vector>
#include <algorithm>

using namespace std;

class Observable;

class Foo
{
    public:
        explicit Foo(int value):value_(value)
        {} 

        ~Foo()
        {
            std::lock_guard<std::mutex> lock(mutex_);
            cout  <<"delete, sleep for 4 seconds" <<endl;
            sleep(4);
            
        }

        void update(int value)
        {   
            cout <<"wait for mutex" <<endl;
            std::lock_guard<std::mutex> lock(mutex_);
            cout <<"got the mutex" <<endl;
            value_ = value;
        }

    private:
        std::mutex mutex_;
        int value_;
};