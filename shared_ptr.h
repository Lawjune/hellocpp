#include <stdio.h>
#include <utility>
#include "shape.h"


class shared_count {
public:
    shared_count() : count_(1) {}
    void add_count()
    {
        ++count_;
    }
    long reduce_count()
    {
        return --count_;
    }
    long get_count() const
    {
        return count_;
    }

private:
    long count_;
};

template <typename T>
class shared_ptr {

public:
    template <typename U>
    friend class shared_ptr;
    explicit shared_ptr(T* ptr = nullptr)
        : ptr_(ptr)
    {
        if (ptr) {
        shared_count_ =
            new shared_count();
        }
    }
    ~shared_ptr()
    {
        if (ptr_ &&
        !shared_count_
            ->reduce_count()) {
        delete ptr_;
        delete shared_count_;
        }
    }

    T* get() const { return ptr_; }

    T& operator*() const { return *ptr_; }  
    T* operator->() const { return ptr_; }  
    operator bool() const { return ptr_; }

    shared_ptr& operator=(shared_ptr& rhs) 
    {
        shared_ptr(rhs).swap(*this);
        return *this;
    }

    shared_ptr& operator=(shared_ptr rhs)
    {
        rhs.swap(*this);
        return *this;
    }

    shared_ptr(const shared_ptr& other)
    {
        ptr_ = other.ptr_;
        if (ptr_) {
        other.shared_count_
            ->add_count();
        shared_count_ =
            other.shared_count_;
        }
    }
    template <typename U>
    shared_ptr(const shared_ptr<U>& other)
    {
        ptr_ = other.ptr_;
        if (ptr_) {
        other.shared_count_
            ->add_count();
        shared_count_ =
            other.shared_count_;
        }
    }
    template <typename U>
    shared_ptr(shared_ptr<U>&& other)
    {
        ptr_ = other.ptr_;
        if (ptr_) {
        shared_count_ =
            other.shared_count_;
        other.ptr_ = nullptr;
        }
    }

    // For casting pointer types
    template <typename U>
    shared_ptr(const shared_ptr<U>& other, T* ptr)
    {
        ptr_ = ptr;
        if (ptr_) {
            other.shared_count_->add_count();
            shared_count_ = other.shared_count_;
        }
    }

    long use_count() const 
    {
        if (ptr_) {
            return shared_count_->get_count();
        } else {
            return 0;
        }
    }

private:
    void swap(shared_ptr& rhs)
    {
        using std::swap;
        swap(ptr_, rhs.ptr_);
        swap(shared_count_, rhs.shared_count_);
    }

    T* ptr_;
    shared_count* shared_count_;
};

template <typename T, typename U>
shared_ptr<T> dynamic_point_cast(const shared_ptr<U>& other)
{
    T *ptr = dynamic_cast<T *>(other.get());
    return shared_ptr<T>(other, ptr);
}

void test_shared_ptr()
{
    shared_ptr<Circle> ptr1(new Circle());
    printf("Use count of ptr1 is %ld\n",
           ptr1.use_count());

    shared_ptr<Shape> ptr2;
    printf("Use count of ptr2 was %ld\n",
           ptr2.use_count());

    ptr2 = ptr1;
    printf("Use count of ptr2 is now %ld\n",
           ptr2.use_count());

    if (ptr1) {
        puts("ptr1 is not empty!");
    }

    puts("Adding test for dynamic_point_cast.\n\n");

    shared_ptr<Circle> ptr3 = dynamic_point_cast<Circle>(ptr2);
    printf("Use count of ptr3 is %ld\n", ptr3.use_count());
}