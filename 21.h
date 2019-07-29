//
// Created by amichai on 29/07/19.
//

#ifndef MARATHON_CPP_2019_SEMESTER_B_21_H
#define MARATHON_CPP_2019_SEMESTER_B_21_H

#include <iostream>
using namespace std;

class SArray {
protected:
    int size;
    bool isLegal(int index) const { return index >= 0 && index < size }
public:
    SArray(int sz): size(sz) {}
    int getSize() const { return size; }
    class BadIndex {
        int index;
    public:
        BadIndex(int i) : index (i) {}
        friend ostream& operator<<(ostream& os, const BadIndex& b);
    };
};

ostream& operator<<(ostream& os, const SArray::BadIndex& b) {
    return os << "Array index " << b.index << " is out of bound.\n";
}

template <typename T, unsigned int N>
class FixedVector : SArray {
public:
    FixedVector(const T array[], unsigned int n) : SArray(N) {
        for (int i=0; i<n && i<N; i++) {
            if (isLegal(i)) FixedVector::array[i] = array[i]; // T has operator=
            else throw BadIndex(i);
        }
    }
    T operator[](const unsigned int index) const throw(SArray::BadIndex) {
        if (!isLegal(index)) {
            throw BadIndex(index);
        }
        return array[index];
    }
    T& operator[](const unsigned int index) throw(SArray::BadIndex) {
        if (!isLegal(index)) {
            throw BadIndex(index);
        }
        return array[index];
    }
    T operator()() const {
        T sum(0); // 0 as argument to T c'tor zero's T's value

        for (int i=0; i<N; i++) {
            sum += array[i];
        }
        return sum;
    };
    void print() const {
        for (int i=0; i<N; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
private:
    T array[N];
};



#endif //MARATHON_CPP_2019_SEMESTER_B_21_H
