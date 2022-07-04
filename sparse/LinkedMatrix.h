//
// Created by lyxn on 2022/7/1.
//

#ifndef MATRIX_SPARSE_LINKEDMATRIX_H
#define MATRIX_SPARSE_LINKEDMATRIX_H

#include <vector>

using namespace std;

namespace sparse {

class LinkedMatrix {
public:
    LinkedMatrix(int size, int numRow, int numCol);

    void add(int r, int c, double v);

    int getRow(int i);

    int getCol(int i);

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }

    string printSymbol();

    string printByCol();

public:
    int numRow;
    int numCol;
    vector<int> colStart;
    vector<int> rowStart;
    vector<double> value;
    vector<int> colLink;
    vector<int> rowLink;

private:
    int capacity;
    int size;
};

}

#endif //MATRIX_SPARSE_LINKEDMATRIX_H
