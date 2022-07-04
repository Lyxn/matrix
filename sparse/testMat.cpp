//
// Created by lyxn on 2022/6/18.
//

#include <iostream>

#include "transform.h"
#include "SortUtil.h"

using namespace std;
using namespace sparse;

CoorSchema mockMat1() {
    CoorSchema mat;
    int m = 4;
    int n = 4;
    vector<int> rows = {0, 3, 2, 1, 1};
    vector<int> cols = {0, 3, 2, 1, 3};
    vector<double> vals = {1, 2, 3, 4, 5};
    mat.numRows = m;
    mat.numCols = n;
    mat.rowIndex = rows;
    mat.colIndex = cols;
    mat.value = vals;
    return mat;
}

void printSorted(const vector<int> &arr, const vector<int> &sorted) {
    for (int i: sorted) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void testSort() {
    vector<int> indexes = {5, 3, 7, 1, 2, 1, 2};
    vector<int> sorted = utils::getSortedIndex(indexes);
    printSorted(indexes, sorted);
}

void testCoorMat() {
    CoorSchema mat = mockMat1();
    cout << mat.printSymbol() << endl;
}

void testPackedMat() {
    CoorSchema cmat = mockMat1();
    cout << cmat.print() << endl;
    PackedMatrix mat = buildPackedFromCoor(cmat);
    cout << mat.print() << endl;
    cout << mat.printSymbol() << endl;
}

void testLinkedMat() {
    CoorSchema cmat = mockMat1();
    cout << cmat.print() << endl;
    LinkedMatrix mat = buildLinkedFromCoor(cmat);
    cout << mat.printSymbol() << endl;
    cout << mat.printByCol() << endl;
}

int main() {
    //testSort();
    //testCoorMat();
    testPackedMat();
    testLinkedMat();
    return 0;
}
