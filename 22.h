//
// Created by amichai on 29/07/19.
//

#ifndef MARATHON_CPP_2019_SEMESTER_B_22_H
#define MARATHON_CPP_2019_SEMESTER_B_22_H
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
#define DATE_STRING 100
class transaction;
ostream& operator<<(ostream&, const transaction& t);

class eBusinessDay {
    char _date[DATE_STRING];
    unsigned int _n;
    transaction* _T;
public:
    /*
    ...
    */
    friend ofstream& operator<<(ofstream&, const eBusinessDay &);
    friend ifstream& operator>>(ifstream&, eBusinessDay &);
    friend char* encrypt(eBusinessDay &e);
};

ofstream &operator<<(ofstream &out, const eBusinessDay &e) {
    out.seekp(0);
    out.write(e._date, DATE_STRING);
    out.write(reinterpret_cast<char*>(&e._n), sizeof(unsigned int));
    for (int i=0; i<e._n; i++) {
        out.write(reinterpret_cast<char*>(&e._T[i]), sizeof(transaction));
    }
    return out;
}

ifstream &operator>>(ifstream &in, eBusinessDay &e) {
    in.seekg(0);
    in.read(e._date, DATE_STRING);
    in.read(reinterpret_cast<char*>(&e._n), sizeof(unsigned int));
    for (int i=0; i<e._n; i++) {
        in.read(reinterpret_cast<char*>(&e._T[i]), sizeof(transaction));
    }
    return in;
}

char* encrypt(const char*);

char* encrypt(eBusinessDay &e) {
    stringstream ss;
    ss << e._date << e._n;

    for (int i=0; i<e._n; i++) {
        ss << e._T[i]; // transaction must support being written to output stream
                       // something like ostream& operator<<(ostream& out, transaction t)
    }
    return encrypt(ss.str().c_str());
}
#endif //MARATHON_CPP_2019_SEMESTER_B_22_H
