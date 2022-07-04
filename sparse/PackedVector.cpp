//
// Created by lyxn on 2022/6/18.
//

#include "PackedVector.h"

#include <sstream>

#include "SortUtil.h"

namespace sparse {

PackedVector::PackedVector(int capacity) : len(0), cap(capacity), index(capacity, 0), value(capacity, 0) {
}

PackedVector::PackedVector(const vector<int> &idxs, const vector<double> &vals) : PackedVector(vals.size()) {
    len = vals.size();
    for (int i = 0; i < len; i++) {
        value[i] = vals[i];
        index[i] = idxs[i];
    }
}

inline void PackedVector::reserve(int size) {
    if (size < cap) {
        return;
    }
    cap = size;
    int idxs[len];
    double vals[len];
    for (int i = 0; i < len; i++) {
        idxs[i] = index[i];
        vals[i] = value[i];
    }
    index.resize(size);
    value.resize(size);
    for (int i = 0; i < len; i++) {
        index[i] = idxs[i];
        value[i] = vals[i];
    }
}

string PackedVector::print() {
    stringstream ss;
    for (int i = 0; i < len; i++) {
        ss << index[i] << "\t";
    }
    ss << "\n";
    for (int i = 0; i < len; i++) {
        ss << value[i] << "\t";
    }
    ss << "\n";
    return ss.str();
}

void PackedVector::swap(int x, int y) {
    utils::swap(index, x, y);
    utils::swap(value, x, y);
}

void PackedVector::sortIdx() {
    sortIdx(0, len - 1);
}

void PackedVector::sortIdx(int low, int high) {
    if (low >= high) {
        return;
    }
    int mid = (low + high) / 2;
    swap(mid, low);
    int p = index[low];
    int l = low;
    int r = high;
    while (l < r) {
        while (l < r && index[r] > p) {
            r--;
        }
        while (l < r && index[l] <= p) {
            l++;
        }
        if (l < r) {
            swap(l, r);
        }
    }
    swap(low, l);
    sortIdx(low, l - 1);
    sortIdx(l + 1, high);
}

inline void PackedVector::addLast(int idx, double val) {
    index[len] = idx;
    value[len] = val;
    len++;
}

double spDotProd(PackedVector &x, PackedVector &y) {
    double res = 0;
    int i1 = 0;
    int i2 = 0;
    while (i1 < x.len && i2 < y.len) {
        if (x.index[i1] == y.index[i2]) {
            res += x.value[i1] * y.value[i2];
            i1++;
            i2++;
        } else if (x.index[i1] < y.index[i2]) {
            i1++;
        } else {
            i2++;
        }
    }
    return res;
}

void spAdd(PackedVector &x, PackedVector &y, double a, int p[]) {
    for (int i = 0; i < y.len; i++) {
        p[y.index[i]] = i;
    }
    int cnt = 0;
    for (int i = 0; i < x.len; i++) {
        int yi = p[x.index[i]];
        if (yi >= 0) {
            x.value[i] += a * y.value[yi];
            p[x.index[i]] = gNilIdx;
            cnt++;
        }
    }
    int fill = y.len - cnt;
    x.reserve(x.len + fill);
    for (int i = 0; i < y.len; i++) {
        int yi = p[y.index[i]];
        if (yi >= 0) {
            x.addLast(y.index[i], a * y.value[i]);
            p[y.index[i]] = gNilIdx;
        }
    }
}

void spAdd1(PackedVector &x, PackedVector &y, double a, int p[]) {
    for (int i = 0; i < x.len; i++) {
        p[x.index[i]] = i;
    }
    int cnt = 0;
    for (int i = 0; i < y.len; i++) {
        int xi = p[y.index[i]];
        if (xi >= 0) {
            x.value[xi] += a * y.value[i];
            p[y.index[i]] = gNilIdx;
            cnt++;
        } else {
            x.addLast(y.index[i], a * y.value[i]);
        }
    }
}

void spAdd(PackedVector &z, PackedVector &x, PackedVector &y, double a) {
    int i1 = 0;
    int i2 = 0;
    z.len = 0;
    while (i1 < x.len && i2 < y.len) {
        if (x.index[i1] == y.index[i2]) {
            z.addLast(x.index[i1], x.value[i1] + a * y.value[i2]);
            i1++;
            i2++;
        } else if (x.index[i1] < y.index[i2]) {
            z.addLast(x.index[i1], x.value[i1]);
            i1++;
        } else {
            z.addLast(y.index[i2], a * y.value[i2]);
            i2++;
        }
    }
    if (i1 < x.len) {
        for (; i1 < x.len; i1++) {
            z.addLast(x.index[i1], x.value[i1]);
        }
    } else {
        for (; i2 < y.len; i2++) {
            z.addLast(y.index[i2], a * y.value[i2]);
        }
    }
}

}