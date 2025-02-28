#ifndef __stack_rpn__
#define __stack_rpn__

#include "stack.hpp"
#include <cassert>
#include <functional>


template <typename T>
void plus(Stack<T> &S){
    T temp1 = S.top(); 
    S.pop();
    T temp2 = S.top();
    S.pop();
    S.push(temp2 + temp1);
};

template <typename T>
void minus(Stack<T> &S){
    T temp1 = S.top(); 
    S.pop();
    T temp2 = S.top();
    S.pop();
    S.push(temp2 - temp1);
};

template <typename T>
void multiplies(Stack<T> &S){
    T temp1 = S.top(); 
    S.pop();
    T temp2 = S.top();
    S.pop();
    S.push(temp2 * temp1);
};

template <typename T>
void divides(Stack<T> &S){
    T temp1 = S.top(); 
    S.pop();
    T temp2 = S.top();
    S.pop();
    S.push(temp2 / temp1);
};

template <typename T>
void negate(Stack<T> &S){
    T temp1 = S.top(); 
    S.pop();
    S.push(-temp1);
};

template <typename T>
Stack<T> &operator<<(Stack<T> &stack, const T &value)
{
    stack.push(value);
    return stack;
};

template <typename T>
Stack<T> &operator<<(Stack<T> &stack, void (*func)(Stack<T> &))
{
    func(stack);
    return stack;
}


#endif // __stack_rpn__