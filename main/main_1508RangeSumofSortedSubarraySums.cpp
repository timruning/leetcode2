//
// Created by 宋峰 on 2021/3/16.
//

#include <iostream>
#include <vector>
#include "../medium/1508RangeSumofSortedSubarraySums.cpp"

using namespace std;

int main() {
    vector<int> vec({1, 2, 3, 4});
    Solution sol;
    int t = sol.rangeSum(vec, 4, 3, 4);
    cout<<t<<endl;
}