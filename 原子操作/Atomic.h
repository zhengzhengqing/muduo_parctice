#include <stdint.h>

class noncopyable
{
  public:
    noncopyable() = default;
    ~noncopyable() = default;
  private:
    noncopyable(const noncopyable&) = delete;
    noncopyable& operator==(const noncopyable&) = delete;

};

template<typename T>
class AtomicIntegerT : public noncopyable
{
  public:
    AtomicIntegerT():value_(0){}
    ~AtomicIntegerT() = default;

    T get()
    {
      // 原子比较和设置操作
      // 将指针ptr中的值与old_value对比，如果相等就将ptr中的值设置new_value并返回old_value，
      // 否则不设置,返回ptr所指向的值
      // __sync_val_compare_and_swap(ptr, old_value, new_value) 
      return __sync_val_compare_and_swap(&value_, 0, 0);
    }

    T getAndAdd(T x)
    {
      // 原子自增操作，先获取值，然后再执行加x
      return __sync_fetch_and_add(&value_, x);
    }

    T AddAndGet(T x)
    {
      return getAndAdd(x) + x;
    }

    // 自增1
    T incrementAndGet()
    {
      return AddAndGet(1);
    }

    // 自减1
    T decrementAndGet()
    {
      return AddAndGet(-1);
    }

    void add(T x)
    {
      getAndAdd(x);
    }

    void increment()
    {
      incrementAndGet();
    }

    void decrement()
    {
      decrementAndGet();
    }

    T getAndSet(T new_value)
    {
      // 原子赋值操作， 将value new_value
      return __sync_lock_test_and_set(&value_, new_value);
    }

  private:
    volatile T value_;
};

typedef AtomicIntegerT<int32_t> AtomicInt32;
typedef AtomicIntegerT<int64_t> AtomicInt64;