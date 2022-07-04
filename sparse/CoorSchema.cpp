//
// Created by lyxn on 2022/6/25.
//

#include "CoorSchema.h"

#include <sstream>

#include "utils/SortUtil.h"

namespace sparse {


string CoorSchema::printSymbol() const {
    stringstream ss;
    vector<int> sorted = utils::getSortedIndex(rowIndex, colIndex);
    int preRow = -1;
    int preCol = -1;
    for (int i : sorted) {
        int r = rowIndex[i];
        int c = colIndex[i];
        if (r != preRow) {
            ss << endl;
            preRow = r;
            preCol = -1;
        }
        for (int j = preCol + 1; j < c; j++) {
            ss << ' ';
        }
        ss << 'x';
        preCol = c;
    }
    ss << endl;
    return ss.str();
}

string CoorSchema::print() const {
    stringstream ss;
    vector<int> sorted = utils::getSortedIndex(rowIndex, colIndex);
    int preRow = -1;
    int preCol = -1;
    for (int i : sorted) {
        int r = rowIndex[i];
        int c = colIndex[i];
        if (r != preRow) {
            ss << endl;
            preRow = r;
            preCol = -1;
        }
        for (int j = preCol + 1; j < c; j++) {
            ss << ' ';
        }
        ss << value[i];
        preCol = c;
    }
    ss << endl;
    return ss.str();
}

}