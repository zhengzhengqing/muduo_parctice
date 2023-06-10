#include "Atomic.h"
#include <iostream>
int main()
{
    AtomicInt64 a4;
    std::cout << a4.getAndSet(5) <<std::endl;
    std::cout << a4.get() <<std::endl;
    return 0;
}