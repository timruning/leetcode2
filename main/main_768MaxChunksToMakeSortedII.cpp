//
// Created by 宋峰 on 2021/3/26.
//

#include <iostream>
#include <vector>

#include "../medium/768MaxChunksToMakeSortedII.cpp"

using namespace std;

int main() {
    vector<int> vec({1,2,3,4,10,6,11,2,1});
    Solution sol;
    int n = sol.maxChunksToSorted(vec);
    cout << n << endl;
}