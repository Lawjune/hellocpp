#include <utility>
#include "shape.h"

template <typename T>
class unique_ptr {
public:
    explicit unique_ptr(T* ptr = nullptr) : ptr_(ptr) {}

    ~unique_ptr() { delete ptr_; }

    T* get() const { return ptr_; }

    T& operator*() const { return *ptr_; }  
    T* operator->() const { return ptr_; }  
    operator bool() const { return ptr_; }

    unique_ptr(unique_ptr& other)
    {
        ptr_ = other.release();
    }

    unique_ptr(unique_ptr&& other)
    {
        ptr_ = other.release();
    }

    template <typename U>
    unique_ptr(unique_ptr<U>& other)
    {
        ptr_ = other.release();
    }

    template <typename U>
    unique_ptr(unique_ptr<U>&& other)
    {
        ptr_ = other.release();
    }

    unique_ptr& operator=(unique_ptr& rhs) 
    {
        unique_ptr(rhs).swap(*this);
        return *this;
    }

    unique_ptr& operator=(unique_ptr rhs)
    {
        rhs.swap(*this);
        return *this;
    }


private:

    T* release()
    {
        T *ptr = ptr_;
        ptr_ = nullptr;
        return ptr;
    }

    void swap(unique_ptr& rhs)
    {
        using std::swap;
        swap(ptr_, rhs.ptr_);
    }

    T* ptr_;
};

void test_uqniue_ptr()
{
    unique_ptr<Shape> ptr1{create_shape(shape_type::Circle)};
    unique_ptr<Shape> ptr2{ptr1};
    std::cout << "ptr2 == ptr1: " << (ptr2 == ptr1) << std::endl;
    std::cout << "ptr1 : " << ptr1.get() << std::endl;
    std::cout << "ptr2 : " << ptr2.get() << std::endl;
    std::cout << "Therefore ptr1 has been accidently empty!" << std::endl;
    std::cout << std::endl;
    unique_ptr<Shape> ptr3;
    // ptr3 = ptr1; // Compiling Error
    ptr3 = std::move(ptr1);
    unique_ptr<Shape> ptr4{std::move(ptr3)};
}