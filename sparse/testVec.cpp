//
// Created by lyxn on 2022/6/18.
//

#include <iostream>

#include "PackedVector.h"

using namespace std;
using namespace sparse;

PackedVector mockVec1() {
    vector<int> idxs = {2, 4, 8};
    vector<double> vals = {1, 2, 3};
    return PackedVector(idxs, vals);
}

PackedVector mockVec2() {
    vector<int> idxs = {2, 5, 7};
    vector<double> vals = {2, 2, 2};
    return PackedVector(idxs, vals);
}

PackedVector mockVec3() {
    vector<int> idxs = {5, 3, 7, 1, 2};
    vector<double> vals = {1, 2, 3, 4, 5};
    return PackedVector(idxs, vals);
}

void testSort() {
    PackedVector vec = mockVec3();
    cout << vec.print() << endl;
    vec.sortIdx();
    cout << vec.print() << endl;
}

void testAdd() {
    PackedVector x = mockVec1();
    PackedVector y = mockVec2();
    PackedVector z = PackedVector(5);
    spAdd(z, x, y, 0.1);
    cout << z.print() << endl;
    int size = 10;
    int p[size];
    fillArray(p, size, gNilIdx);
    spAdd(x, y, 0.1, p);
    cout << x.print() << endl;
    x = mockVec1();
    spAdd1(x, y, 0.1, p);
    cout << x.print() << endl;
}

void testDotProd() {
    PackedVector x = mockVec1();
    double a = spDotProd(x, x);
    cout << a << endl;
    cout << x.print() << endl;
}

int main() {
    testDotProd();
    testSort();
    testAdd();
    return 0;
}
