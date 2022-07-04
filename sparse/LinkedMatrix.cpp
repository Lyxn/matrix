//
// Created by lyxn on 2022/7/1.
//

#include "LinkedMatrix.h"

#include "StringUtil.h"

namespace sparse {

LinkedMatrix::LinkedMatrix(int capacity, int numRow, int numCol) :
        capacity(capacity), size(0), numRow(numRow), numCol(numCol),
        colStart(numRow, -1), rowStart(numCol, -1),
        rowLink(capacity, 0), colLink(capacity, 0), value(capacity, 0) {}

void LinkedMatrix::add(int r, int c, double v) {
    int i = size;
    value[i] = v;
    int rs = rowStart[r];
    if (rs < 0) {
        rowLink[i] = -r - 1;
    } else {
        rowLink[i] = rs;
    }
    rowStart[r] = i;
    int cs = colStart[c];
    if (cs < 0) {
        colLink[i] = -c - 1;
    } else {
        colLink[i] = cs;
    }
    colStart[c] = i;
    size++;
}

int LinkedMatrix::getRow(int i) {
    int x = rowLink[i];
    while (x >= 0) {
        x = rowLink[x];
    }
    return -x - 1;
}

int LinkedMatrix::getCol(int i) {
    int x = colLink[i];
    while (x >= 0) {
        x = colLink[x];
    }
    return -x - 1;
}

string LinkedMatrix::printSymbol() {
    stringstream ss;
    vector<int> tmp;
    for (int r = 0; r < numRow; r++) {
        tmp.clear();
        int x = rowStart[r];
        while (x >= 0) {
            int c = getCol(x);
            tmp.emplace_back(c);
            x = rowLink[x];
        }
        sort(tmp.begin(), tmp.end());
        utils::fmtRowSymbol(tmp, ss);
    }
    return ss.str();
}

string LinkedMatrix::printByCol() {
    stringstream ss;
    vector<int> tmp;
    for (int c = 0; c < numCol; c++) {
        tmp.clear();
        int x = colStart[c];
        while (x >= 0) {
            int r = getRow(x);
            tmp.emplace_back(r);
            x = colLink[x];
        }
        sort(tmp.begin(), tmp.end());
        utils::fmtRowSymbol(tmp, ss);
    }
    return ss.str();
}

}