//
// Created by lyxn on 2022/6/18.
//

#ifndef MATRIX_SPARSE_PACKEDVECTOR_H
#define MATRIX_SPARSE_PACKEDVECTOR_H

#include <vector>

using namespace std;

namespace sparse {

const int gNilIdx = -1;

class PackedVector {
public:
    PackedVector(int capacity);

    PackedVector(const vector<int> &idxs, const vector<double> &vals);

    void reserve(int size);

    void addLast(int idx, double val);

    void sortIdx();

    string print();

public:
    int len;

    int cap;

    vector<double> value;

    vector<int> index;

private:
    void swap(int x, int y);

    void sortIdx(int low, int high);
};


template<class T>
void fillArray(T arr[], int size, T val) {
    for (int i = 0; i < size; i++) {
        arr[i] = val;
    }
}

double spDotProd(PackedVector &x, PackedVector &y);

void spAdd(PackedVector &x, PackedVector &y, double a, int p[]);

void spAdd1(PackedVector &x, PackedVector &y, double a, int p[]);

void spAdd(PackedVector &z, PackedVector &x, PackedVector &y, double a);

}

#endif //MATRIX_SPARSE_PACKEDVECTOR_H
