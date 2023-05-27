#include <thread>
#include <functional> 
#include "request.h"
int main()
{
    Request res;


    std::thread t1(std::bind(&Request::process, &res));
    std::thread t2(std::bind(&Request::product, &res));

    t1.join();
    t1.join();
    
    return 0;
}