
#include <algorithm>
#include <iostream>

using namespace std;

template <class InIter, class OutIter, class Comperator>
void SortCopy(InIter first, InIter last, OutIter result, Comperator cmp) {
    if (first >= last) {
        return;
    }

    InIter smallest = first;

    /* find smallest item */
    for (InIter i = first; i<last; i++) {
        if (cmp(*i ,*smallest)) {
            smallest = i;
        }
    }

    /* put smallest item first */
    iter_swap(smallest, first);

    /* copy smallest item to result */
    *result = *first;

    /* do the same for the second item and so on.. */
    SortCopy(++first, last, ++result, cmp);
};

bool compare(int a, int b) {
    return a < b;
}

void print_vector(vector<int> a) {
    for (int i : a) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<int> a(20);
    vector<int> b(20);

    for (int i=0; i<20; i++) {
        a[i] = rand()%100;
    }

    cout << "a" << endl;
    print_vector(a);
    SortCopy(a.begin(), a.end(), b.begin(), compare);
    cout << "b" << endl;
    print_vector(b);
}