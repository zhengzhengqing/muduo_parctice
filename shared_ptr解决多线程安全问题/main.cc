#include "foo.h"
#include "observer.h"

void test_destroy(Foo* foo)
{
    delete foo;
    foo = nullptr;
}

void test_update(Foo* foo)
{
    if(foo)
        foo->update(4);
}

void test_observable(Observable* obj)
{
    while(1)
    {
        obj->notify_observers();
        sleep(1);
    }
}

void test_observer(Observable* obj)
{
    Observer s;
    s.observ(obj);
}

int main()
{

 // test 1, 多个线程同时操作裸指针时，会有线程安全问题
#if 0
    Foo *foo = new Foo(1);

    std:thread t1(test_destroy, foo);
    sleep(1);
    std::thread t2(test_update, foo);

    t1.join();
    t2.join();

#endif

// test 2 多线程安全的Observer有多难
// 加锁不是一个好的方法
# if 1
    Observable * ob = new Observable;
    
    std::thread t3(test_observer, ob);
    std::thread t4(test_observable, ob);

    t3.join();
    t4.join();
#endif
    return 0;
}