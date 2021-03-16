//
// Created by 宋峰 on 2021/3/11.
//

#include <vector>
#include <iostream>
#include "../medium/1031MaximumSumofTwoNon-OverlappingSubarrays.cpp"

using namespace std;

int main() {
    Solution sol;
    vector<int> vec({3, 8, 1, 3, 2, 1, 8, 9, 0});
    int n = sol.maxSumTwoNoOverlap(vec, 3, 2);
    cout << n << endl;
}