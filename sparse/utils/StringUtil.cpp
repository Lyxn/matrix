//
// Created by lyxn on 2022/7/2.
//

#include <iostream>
#include "StringUtil.h"

namespace utils {

void printVector(const vector<int> &vec) {
    for (auto x: vec) {
        cout << x << "\t";
    }
    cout << endl;
}

void fmtRowSymbol(const vector<int> &cols, stringstream &ss) {
    int pre = -1;
    for (int c: cols) {
        for (int i = pre + 1; i < c; i++) {
            ss << ' ';
        }
        pre = c;
        ss << 'x';
    }
    ss << endl;
}

}
