#include <stdio.h>
#include <assert.h>
#include <pthread.h>

class noncopyable
{
    public:
        noncopyable() = default;
        ~noncopyable() = default;
        
        
        
    private:
    	noncopyable(const noncopyable& ) = delete;
    	noncopyable& operator=(const noncopyable&) = delete;
};

template <typename T>
class SingleTon : public noncopyable
{
    public:
        SingleTon() = delete;
        ~SingleTon() = delete;
        
        // 如果写成析构函数的方式去释放内存，析构函数不会被调用，内存将无法释放，为什么？
        /*
        ~SingleTon()
        {
            std::cout <<"destroy" <<std::endl;
            typedef char T_must_be_complete_type[sizeof(T) == 0 ? -1 : 1];
            T_must_be_complete_type dummy;
            delete value_;
            value_ = NULL;
        }
        */
        
        
        static T& instance()
        {
            pthread_once(&ponce_, &SingleTon::init);
            assert(value_ != NULL);
            return *value_;
             
        }
    
    private:
        static void init()
        {
            value_ = new T();
            ::atexit(destroy);
        }
        
        static void destroy()
        {
            std::cout <<"destroy" <<std::endl;
            typedef char T_must_be_complete_type[sizeof(T) == 0 ? -1 : 1];
            T_must_be_complete_type dummy;
            delete value_;
            value_ = NULL;
        }
     
    
    private:
    	static pthread_once_t ponce_;
    	static T * value_;
    	
};

template<typename T>
pthread_once_t SingleTon<T>::ponce_ = PTHREAD_ONCE_INIT;

template<typename T>
T* SingleTon<T>::value_ = NULL;
