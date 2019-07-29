//
// Created by amichai on 29/07/19.
//

#ifndef MARATHON_CPP_2019_SEMESTER_B_19_H
#define MARATHON_CPP_2019_SEMESTER_B_19_H
#include <set>
#include <ostream>

using namespace std;

template <typename K, typename V>
class AMap {
public:
    class InvalidKeyException : exception {};
    pair<K, V>* search(const K& key) const;
    void insert(const K& key, const V& value);
    void remove(const K& key) throw(InvalidKeyException);
    pair<K, V> operator[](const K& key) const throw(InvalidKeyException);
    pair<K, V>& operator[](const K& key);
    int size();
    void print(ostream& out) const;
private:
    std::set<pair<K, V>> map;
};

template<typename K, typename V>
pair<K, V> AMap<K, V>::operator[](const K &key) const {
    pair<K, V> *res = search(key);
    if (res == nullptr) {
        throw InvalidKeyException();
    }
    return *res;
}

template<typename K, typename V>
pair<K, V> &AMap<K, V>::operator[](const K &key) {
    pair<K, V> *res = search(key);
    if (res == nullptr) {
        insert(key, nullptr);
    }
    return *search(key);
}

#endif //MARATHON_CPP_2019_SEMESTER_B_19_H
