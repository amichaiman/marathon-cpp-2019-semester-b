#ifndef MARATHON_CPP_2019_SEMESTER_B_15_A_H
#define MARATHON_CPP_2019_SEMESTER_B_15_A_H
#include <vector>

template <typename T>
class Stack {
public:
    class EmptyStackException : std::exception {};
    bool push(const T& elem);
    T& top() const throw(EmptyStackException);
    void pop() throw(EmptyStackException);
    int size() const;
    bool empty() const;
private:
    std::vector<T> v;
};

#endif //MARATHON_CPP_2019_SEMESTER_B_15_A_H
