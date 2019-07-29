//
// Created by amichai on 29/07/19.
//

#ifndef MARATHON_CPP_2019_SEMESTER_B_20_H
#define MARATHON_CPP_2019_SEMESTER_B_20_H
#include <vector>
#include <iostream>

using namespace std;

template <typename LanguageChar, typename Container = vector>
class ABCsequence {
public:
    ABCsequence(const LanguageChar array[]);
    ABCsequence(const Container& container);
    ABCsequence& ABCsequence(const ABCsequence& rhs);
    ABCsequence& operator=(const ABCsequence& rhs);
    ABCsequence& operator=(const LanguageChar array[]);
    LanguageChar operator[](const int index) const;
    LanguageChar& operator[](const int index);
    void operator+=(const LanguageChar character);
    void operator+=(const LanguageChar sequence[]);
    void operator--();
    int size() const;
    int empty() const;
    int reverse();

private:
    Container<LanguageChar> container;
};

/*
 * container's iterator must be bi-directional iterator
 * container's iterator must have operator < defined
 * */
template<typename LanguageChar, typename Container>
int ABCsequence<LanguageChar, Container>::reverse() {
    Container::iterator it_left = container.begin();
    Container::iterator it_right = container.end();

    while (it_left < --it_right) {
        swap(it_left, it_right);
        it_left++;
    }
}

#endif //MARATHON_CPP_2019_SEMESTER_B_20_H


int main() {
    const Jchar* arigato = "きゃっかんてき";
    ABCsequence<Jchar> sequence(arigato);
    sequence.reverse();
    for (int i=0; i<sequence.size(); i++) {
        cout << sequence[i] << endl;
    }
}
