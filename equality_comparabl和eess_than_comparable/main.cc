#include <iostream>
#include <boost/operators.hpp>

/**
 * less_than_comparable 要求类型T具有以下语义。
  bool operator<(const T&,const T&); 
  bool operator>(const T&,const T&); 
  bool operator<=(const T&,const T&);
  bool operator>=(const T&,const T&);

  要派生自 boost::less_than_comparable, 派生类(T)必须提供：
  bool operator<(const T&, const T&);

 * equality_comparable 要求类型T具有以下语义。
  bool operator==(const T&,const T&);
  bool operator!=(const T&,const T&);

  要派生自 boost::equality_comparable, 派生类(T)必须提供：
  bool operator==(const T&,const T&);


 * **/

class Age : public boost::equality_comparable1<Age>,
            public boost::less_than_comparable<Age>
{
  public:
    Age():age_(0){}
    explicit Age(int64_t age):age_(age){}
    
    //写法1
    // inline bool operator==(const Age& age)
    // {
    //     return age_ == age.age_;
    // }

    int64_t get_age()
    {
        return age_;
    }


  private:
    int64_t age_;
};

inline bool operator<(Age age1, Age age2)
{
    return age1.get_age() < age2.get_age();
}

// 写法2
inline bool operator==(Age age1, Age age2)
{
    return age1.get_age() == age2.get_age();
}

int main()
{
    Age age1(100);
    Age age2(99);
    Age age3(99);
    

    if(age1 > age2)
    {
        std::cout <<"ok" <<std::endl;
    }

    if(age1 >= age2)
    {
        std::cout <<"ok" <<std::endl;
    }

    if(age1 != age2)
    {
        std::cout <<"ok" <<std::endl;
    }

    if(age2 == age3)
    {
        std::cout <<"ok" <<std::endl;
    }

    return 0;
}
