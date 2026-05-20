#include <iostream>
#include <cstddef>
#include <cassert>

using namespace std;

class Vector {
private:
    int* arr;
    size_t sz;
    size_t cap;

    void checkAndDouble();

public:
    Vector();
    ~Vector();

    size_t size() {
        return sz;
    }

    int& operator[](size_t pos) {
        return arr[pos];
    }

    void append(int val);

    void insert(int pos, int val);

    void print(string name) {
        for (size_t i = 0; i < sz; i++) {
            cout << name << "[" << i << "]: " << arr[i] << endl;
        }
    }
};

Vector::Vector() {
    cap = 1;
    sz = 0;
    arr = new int[cap];
}

Vector::~Vector() {
    delete[] arr;
}

void Vector::checkAndDouble() {
    if (sz < cap) return;

    size_t newCap = 2 * cap;

    int *newArr = new int[newCap];

    for (int i = 0; i < sz; ++i) {
        newArr[i] = arr[i];
    }

    delete[] arr;
    arr = newArr;
    cap = newCap;
}

void Vector::append(int val) {
    checkAndDouble();
    assert(sz < cap);
    arr[sz++] = val;
}

void Vector::insert(int pos, int val) {
    if (sz+1 > cap) checkAndDouble();

    for (int i = sz; i < pos; --i) {
        arr[i-1] = arr[i];
    }

    arr[pos] = val;
    sz++;
}



int main(int argc, char** argv) {
    size_t n = stoi(argv[1]);
    Vector v;

    for (size_t i = 0; i < n; ++i) {
        v.append(i);
    }

    //v.print("v");

    return 0;
}
