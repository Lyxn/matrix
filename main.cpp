#include <iostream>
#include <vector>

#include "StringUtil.h"

using namespace std;
using namespace utils;

void testVec() {
    vector<int> vec = {1, 3, 4, 2, 0};
    cout << vec.capacity() << endl;
    printVector(vec);
    vec.resize(10);
    cout << vec.capacity() << "\t" << vec.size() << endl;
    printVector(vec);
    sort(vec.begin(), vec.end(), [](int x, int y) -> bool { return x > y; });
}

int main() {
    testVec();
}
