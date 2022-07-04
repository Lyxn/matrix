//
// Created by lyxn on 2022/6/25.
//

#include "PackedMatrix.h"

#include <sstream>

#include "SortUtil.h"
#include "StringUtil.h"

namespace sparse {

/**
 * TODO
 * 1. sort row
 * 2. transpose
 */
string PackedMatrix::printSymbol() const {
    stringstream ss;
    vector<int> tmp;
    for (int i = 0; i < numCols; i++) {
        int start = colStart[i];
        int len = lenCol[i];
        if (len == 0) {
            ss << endl;
            continue;
        }
        tmp.clear();
        for (int j = start; j < start + len; j++) {
            tmp.emplace_back(rowIndex[j]);
        }
        sort(tmp.begin(), tmp.end());
        utils::fmtRowSymbol(tmp, ss);
    }
    return ss.str();
}

string PackedMatrix::print() const {
    stringstream ss;
    for (int i = 0; i < numCols; i++) {
        int start = colStart[i];
        int len = lenCol[i];
        if (len == 0) {
            ss << endl;
            continue;
        }
        int pre = -1;
        for (int j = start; j < start + len; j++) {
            int r = rowIndex[j];
            for (int k = pre + 1; k < r; k++) {
                ss << ' ';
            }
            ss << value[j];
            pre = r;
        }
        ss << endl;
    }
    return ss.str();
}
}
