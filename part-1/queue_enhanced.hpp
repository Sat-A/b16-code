#ifndef __queue_enhanced__
#define __queue_enhanced__

#include <cassert>
#include <vector>

#include "queue.hpp"

template <typename T> class Dequeue : public Queue<T>
{
  public:
    // Inherit the constructors of Queue<T>
    using Queue<T>::Queue;

    // Access the element at the back of the queue
    T &back()
    {
        return this->_storage[_tail()];
    }

    // Const-access the element at the back of the queue
    const T &back() const
    {
        return this->_storage[_tail()];
    }

    // Add a new element to the front of the queue by copying
    void enqueue_front(const T &value)
    {
        this->_storage[this->_position + this->_size + 1] = value;
        this->_size++;
    }

    // Remove the element at the back of the queue
    void dequeue_back()
    {
        this->_position++;
        this->_size--;
    }

    // Remove all elements from the queue
    void clear() { 
        while(this->_size > 0){
            this->_size--;
        }
    }

  protected:
    // Return the index of the element at the back of the queue
    size_t _tail() const
    {
        return this->_position+1;
    }
};

#endif // __queue_enhanced__