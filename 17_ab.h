#ifndef MARATHON_CPP_2019_SEMESTER_B_17_H
#define MARATHON_CPP_2019_SEMESTER_B_17_H

#include <string>
using namespace std;

template <unsigned int N>
class BitSet {
public:
    explicit BitSet();
    BitSet(const bool *bool_bit_set);
    bool operator[](const unsigned int index) const;
    void set(const unsigned int index, const bool value);
    void flip(const unsigned int index);
    void flip();
    int count() const;
    int size() const;
    operator string() const;

    class BitSetIterator {
    private:
        int index;
        BitSet &bit_set;
    public:
        BitSetIterator(BitSet& bit_set, int index);
        BitSetIterator(const BitSetIterator& rhs);
        BitSetIterator& operator[](unsigned int index);
        BitSetIterator& operator--();
        BitSetIterator& operator++();
        bool operator!=() const;
        bool operator==() const;
        bool operator*() const;
    };

    BitSetIterator begin() const;
    BitSetIterator end() const;

private:
    const int BITS_IN_BYTE = 8;
    unsigned char bit_set[N/BITS_IN_BYTE + (N%BITS_IN_BYTE == 0)];
};
#endif //MARATHON_CPP_2019_SEMESTER_B_17_H
