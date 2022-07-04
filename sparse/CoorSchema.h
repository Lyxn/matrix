//
// Created by lyxn on 2022/6/25.
//

#ifndef SPARSE_MATRIX_COOR_SCHEMA_H
#define SPARSE_MATRIX_COOR_SCHEMA_H

#include <vector>

using namespace std;

namespace sparse {

class CoorSchema {
public:
    CoorSchema() : numRows(0), numCols(0) {
    }

    string print() const;

    string printSymbol() const;

public:
    int numRows;
    int numCols;
    vector<int> rowIndex;
    vector<int> colIndex;
    vector<double> value;

};


}

#endif //SPARSE_MATRIX_COOR_SCHEMA_H
