//
// Created by lyxn on 2022/7/2.
//

#ifndef MATRIX_STRINGUTIL_H
#define MATRIX_STRINGUTIL_H

#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

namespace utils {

template<class T>
void printVector(const vector<T> &vec) {
    for (auto x: vec) {
        cout << x << '\t';
    }
    cout << endl;
}

void fmtRowSymbol(const vector<int> &cols, stringstream &ss);

}

#endif //MATRIX_STRINGUTIL_H
