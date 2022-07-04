//
// Created by lyxn on 2022/6/25.
//

#ifndef MATRIX_SPARSE_PACKEDMATRIX_H
#define MATRIX_SPARSE_PACKEDMATRIX_H

#include <string>
#include <vector>

using namespace std;

namespace sparse {

class PackedMatrix {
public:
    PackedMatrix() : PackedMatrix(0, 0) {
    }

    PackedMatrix(int m, int n) : numRows(m), numCols(n) {
    }

    string print() const;

    string printSymbol() const;

public:
    int numRows;
    int numCols;
    vector<int> lenCol;
    vector<int> colStart;
    vector<int> rowIndex;
    vector<double> value;
};

}

#endif //MATRIX_SPARSE_PACKEDMATRIX_H
