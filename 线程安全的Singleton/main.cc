#include <iostream>
#include "SingleTon.h"
using namespace std;

class S
{
   public:
   	void set_name(const string& name)
   	{
   	    name_ = name;
   	}
   	
   	void print_name()
   	{
   	    cout <<"name = " <<name_ <<endl;
   	}
   	
   private:
       string name_;
};

int main()
{
    

    SingleTon<S>::instance().set_name("you");
    printf("address =  %p\n", &SingleTon<S>::instance());
    
    SingleTon<S>::instance().print_name();
    printf("address =  %p\n", &SingleTon<S>::instance());

    return 0;
}
