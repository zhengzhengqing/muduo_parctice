#pragma once
#include <iostream>
#include <mutex>
#include <unistd.h>
#include <condition_variable>

using namespace std;

class Request
{
    public:
        Request():is_ready_(false) {}
        ~Request() = default;
        void process()
        {
            while(true)
            {
                {
                    std::unique_lock<std::mutex> lock(mutex_);
                    cout <<"wait for true" <<endl;
                    condition_.wait(lock, [this](){ return is_ready_;});
                    cout <<"got" <<endl;
                    is_ready_ = false;
                }
                
                sleep(1);
            }
        }

        void product()
        {
            while(true)
            {
                {
                    std::unique_lock<std::mutex> lock(mutex_);
                    is_ready_  = true;
                    condition_.notify_one();
                    cout <<"notify" <<endl;
                }
                
                sleep(5);
            }
        }

    public:
        bool is_ready_;
    private:
        
        std::mutex mutex_;
        std::condition_variable condition_;
        
};