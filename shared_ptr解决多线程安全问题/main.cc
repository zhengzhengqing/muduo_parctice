#include "foo.h"
#include "observer.h"
#include "stock.h"
//#include "observable.h"

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
    // Observer s;
    // s.observ(obj);
    
    shared_ptr<BObserver> ptr(new Observer);
    obj->register_(ptr);
    sleep(3);
}

void doit(shared_ptr<FooTest>& ptr)
{
    ptr->doit();
}

void read_(shared_ptr<FooTest>& ptr, std::mutex& mutex_)
{
    shared_ptr<FooTest> p1;
    {
        std::unique_lock<std::mutex> lock(mutex_);
        p1 = ptr;
    }
    doit(p1);
}

void write_(shared_ptr<FooTest>& ptr, std::mutex& mutex_)
{
    shared_ptr<FooTest> new_ptr(new FooTest(2));
    shared_ptr<FooTest> ptr_2 = new_ptr;
    {
        std::unique_lock<std::mutex> lock(mutex_);
        //ptr = new_ptr; //如果ptr的引用基数为1,此种写法导致ptr所指向对象的析构动作在临界去以内，增加了临界去的长度
        swap(ptr, ptr_2); // 这种写法可以把对象的析构延迟到临界区外
    }
    cout <<"wirte done" <<endl;
    doit(new_ptr);
}



int main()
{

 // test 1, 多个线程同时操作原始指针时，会有线程安全问题
#if 0
    Foo *foo = new Foo(1);

    std:thread t1(test_destroy, foo);
    sleep(1);
    std::thread t2(test_update, foo);

    t1.join();
    t2.join();

    delete foo;

#endif

// test 2， 1.4小节 多线程安全的Observer有多难，未使用智能指针
// 加锁不是一个好的方法
# if 0
    Observable * ob = new Observable;
    
    std::thread t3(test_observer, ob);
    std::thread t4(test_observable, ob);

    t3.join();
    t4.join();
    delete ob;

#endif

// test 3，1.6小节 神器shread_ptr/weak_ptr
#if 0
    Observable * ob = new Observable;
    
    std::thread t5(test_observer, ob);
    std::thread t6(test_observable, ob);

    t5.join();
    t6.join();
    delete ob;

#endif

#if 0 //test4, 1.9在谈shared_ptr线程安全
    
    shared_ptr<FooTest> g_ptr(new FooTest(1));
    std::mutex g_mutex;
    
    // shared_ptr的读操作
    //read_(g_ptr, g_mutex);

    // shared_ptr的写操作
    write_(g_ptr, g_mutex);


#endif

#if 1 // test5, 1.11 对象池
    // StockFactory* factory = new StockFactory;
    // {
    //     auto ptr = factory->get("google");
    //     ptr->print();
    //     factory->print_size();
    // }
    // factory->print_size();

    // 测试 StockFactory 先于 Stock 对象析构,core dump
    shared_ptr<Stock> p;
    {
        StockFactory factory;
        p = factory.get("google");
    }
    p->print();
    cout <<"StockFactory not existed" <<endl;

#endif
    return 0;
}