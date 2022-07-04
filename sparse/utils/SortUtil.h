//
// Created by lyxn on 2022/6/25.
//

#ifndef MATRIX_SORTUTIL_H
#define MATRIX_SORTUTIL_H

#include <vector>

using namespace std;

namespace utils {

template<class T>
void swap(vector<T> &vec, int x, int y) {
    int tmp = vec[x];
    vec[x] = vec[y];
    vec[y] = tmp;
}

vector<int> newRange(int size);

void sortInts(function<int(int, int)> cmp, vector<int> &indexes, int low, int high);

vector<int> getSortedIndex(const vector<int> &rows, const vector<int> &cols);

vector<int> getSortedIndex(const vector<int> &arr);

}
#endif //MATRIX_SORTUTIL_H
