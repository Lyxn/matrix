//
// Created by lyxn on 2022/6/25.
//

#include "SortUtil.h"

#include <cstdlib>
#include <functional>

namespace utils {

inline vector<int> newRange(int size) {
    vector<int> res(size);
    for (int i = 0; i < size; i++) {
        res[i] = i;
    }
    return res;
}

void sortInts(function<int(int, int)> cmp, vector<int> &indexes, int low, int high) {
    if (low >= high) {
        return;
    }
    int rnd = rand() % (high - low + 1) + low;
    swap(indexes, rnd, low);
    int p = indexes[low];
    int l = low;
    int r = high;
    while (l < r) {
        while (l < r && cmp(indexes[r], p) > 0) {
            r--;
        }
        while (l < r && cmp(indexes[l], p) <= 0) {
            l++;
        }
        if (l < r) {
            swap(indexes, l, r);
        }
    }
    swap(indexes, low, l);
    sortInts(cmp, indexes, low, l - 1);
    sortInts(cmp, indexes, l + 1, high);
}

vector<int> getSortedIndex(const vector<int> &arr) {
    int size = arr.size();
    vector<int> indexes = newRange(size);
    auto cmp = [&](int x, int y) -> int {
        return arr[x] - arr[y];
    };
    sortInts(cmp, indexes, 0, size - 1);
    return indexes;
}

vector<int> getSortedIndex(const vector<int> &rows, const vector<int> &cols) {
    int size = rows.size();
    vector<int> indexes = newRange(size);
    auto cmp = [&](int x, int y) -> int {
        if (rows[x] == rows[y]) {
            return cols[x] - cols[y];
        }
        return rows[x] - rows[y];
    };
    sortInts(cmp, indexes, 0, size - 1);
    return indexes;
}

}