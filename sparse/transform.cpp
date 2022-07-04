//
// Created by lyxn on 2022/7/2.
//

#include "transform.h"

#include "SortUtil.h"

namespace sparse {

PackedMatrix buildPackedFromCoor(const CoorSchema &mat) {
    int m = mat.numRows;
    int n = mat.numCols;
    int size = mat.value.size();
    vector<int> sorted = utils::getSortedIndex(mat.colIndex, mat.rowIndex);
    vector<int> lenCol(n, 0);
    vector<int> colStart(n, -1);
    int preCol = -1;
    for (int i = 0; i < size; i++) {
        int k = sorted[i];
        int c = mat.colIndex[k];
        if (c != preCol) {
            colStart[c] = i;
            if (preCol >= 0) {
                lenCol[preCol] = i - colStart[preCol];
            }
            preCol = c;
        }
    }
    lenCol[preCol] = size - colStart[preCol];
    vector<int> rowIndex(size);
    vector<double> value(size);
    for (int i = 0; i < size; i++) {
        int x = sorted[i];
        int r = mat.rowIndex[x];
        value[i] = mat.value[x];
        rowIndex[i] = r;
    }
    PackedMatrix pack(m, n);
    pack.lenCol = lenCol;
    pack.colStart = colStart;
    pack.rowIndex = rowIndex;
    pack.value = value;
    return pack;
}

LinkedMatrix buildLinkedFromCoor(const CoorSchema &mat) {
    int m = mat.numRows;
    int n = mat.numCols;
    int capacity = mat.value.size() + 1;
    vector<int> sorted = utils::getSortedIndex(mat.colIndex, mat.rowIndex);
    LinkedMatrix lnk(capacity, m, n);
    for (int idx: sorted) {
        lnk.add(mat.rowIndex[idx], mat.colIndex[idx], mat.value[idx]);
    }
    return lnk;
}

} // sparse