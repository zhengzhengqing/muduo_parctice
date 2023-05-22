# 知识点补充

## 1.不同头文件中类的相互引用规则

头文件A.h

```c++
#include "B.h"
class A
{
    public:
    	A() = default;
        ~A() = default;
    public:
    	B b;
};
```

---

头文件B.h

```c++
class A;  // 前置定义，在B中只能定义A类型的指针，不能定义value类型，因为编译器不知道创建A对象需要多少的内存
class B
{
    B();
    ~B();
    public:
    	A* a ; // 指针为4个字节
};
```

B.cc文件

```c++
#include "A.h"
B::B()
{}

B::~B()
{}
 
```



main.cc

```c++
#include "A.h"
int main()
{
    //
}
```

