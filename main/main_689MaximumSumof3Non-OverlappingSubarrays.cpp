//
// Created by 宋峰 on 2021/3/29.
//

#include <iostream>
#include <vector>
#include "../medium/689MaximumSumof3Non-OverlappingSubarrays.cpp"

using namespace std;

int main() {
    Solution sol;
    vector<int> vec({1, 2, 1, 2, 6, 7, 5, 1, 8, 8, 1, 7, 2, 3, 10, 5, 3, 4, 10, 12, 3, 9});
    vector<int> result = sol.maxSumOfThreeSubarrays(vec, 3);
    for (auto v:result) {
        cout << v << " ";
    }
    cout << endl;
}