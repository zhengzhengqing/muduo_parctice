#pragma once
#include <assert.h>
#include <pthread.h>
#include <iostream>

#define MCHECK(ret) ({ __typeof__ (ret) errnum = (ret);         \
                       assert(errnum == 0); (void) errnum;})

class MutexLock 
{
    public:
        MutexLock()
        {
            //MCHECK(pthread_mutex_init(&mutex_, NULL));
            pthread_mutex_init(&mutex_, NULL);
        }

        ~MutexLock()
        {
            pthread_mutex_destroy(&mutex_);
            //MCHECK(pthread_mutex_destroy(&mutex_));
        }

        void lock()
        {
            pthread_mutex_lock(&mutex_);
            //MCHECK(pthread_mutex_lock(&mutex_));
        }

        void unlock()
        {
            pthread_mutex_unlock(&mutex_);
            //MCHECK(pthread_mutex_unlock(&mutex_));
        }

        pthread_mutex_t * get_mutex()
        {
            return & mutex_;
        }


    
    private:
        pthread_mutex_t mutex_;
};

class MutexLockGuard  
{
    public:
        explicit MutexLockGuard(MutexLock & mutex):mutex_(mutex)
        {
            mutex_.lock();
        }

        ~MutexLockGuard()
        {
            
            std::cout <<"destroy" <<std::endl;
            mutex_.unlock();
        }

    private:
        MutexLock &mutex_;
};


