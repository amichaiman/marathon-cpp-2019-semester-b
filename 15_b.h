#ifndef MARATHON_CPP_2019_SEMESTER_B_15_B_H
#define MARATHON_CPP_2019_SEMESTER_B_15_B_H
#include "15_a.h"

template <typename T>
class Queue {
    class EmptyQueueException : std::exception {};
    bool enqueue(const T& elem);
    T& front() throw(EmptyQueueException);
    T& back() throw(EmptyQueueException);
    void dequeue() throw(EmptyQueueException);
private:
    Stack<T> a;
    Stack<T> b;
    void transferBetweenStacks(Stack<T>& a, Stack<T>& b);
};

/* transfers a to b */
template<typename T>
void Queue<T>::transferBetweenStacks(Stack<T> &a, Stack<T> &b) {
    while (!a.empty()) {
        b.push(a.top());
        a.pop();
    }
}

template<typename T>
bool Queue<T>::enqueue(const T &elem) {
    return a.push(elem);
}

template<typename T>
T &Queue<T>::front() {
    if (b.empty()) {
        transferBetweenStacks(a, b);
    }
    return b.top();
}

template<typename T>
T &Queue<T>::back() {
    if (a.empty()) {
        transferBetweenStacks(b, a);
    }
    return a.top();
}

template<typename T>
void Queue<T>::dequeue() {
    if (b.empty()) {
        transferBetweenStacks(a, b);
    }
    b.pop();
}

#endif //MARATHON_CPP_2019_SEMESTER_B_15_B_H
