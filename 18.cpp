#include <iostream>
using namespace std;

class Based {
public:
    int getVal() const {
        return val;
    }

    int getBase() const {
        return base;
    }

    Based(int val, int base) {
        Based::val = val;
        Based::base = base;
    }

private:
    int val;
    int base;
};

const char e_digits[] = "0123456789abcdefghijklmnopqrstuvwxyz";

std::ostream& operator<<(std::ostream& output, Based v) {
    int const buffsize = 128;
    char buffer[buffsize];
    int value=v.getVal(), base=v.getBase();
    bool negative = value<0;
    if (negative) value=-value;
    int endpos = buffsize;

    buffer[--endpos] = '\0';

    do {
        buffer[--endpos] = e_digits[value%base];
    } while(value /= base);

    if (negative) buffer[--endpos] = '-';

    return output << &buffer[endpos];
}

int main() {
    Based b(11, 3);
    cout << b << endl;
}
