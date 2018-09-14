//
// Created by 宋峰 on 2018/9/1.
//

#include <iostream>
#include <vector>
#include "../algorithm/713SubarrayProductLessThanK.cpp"

using namespace std;

int main() {
    Solution solution;
    int a[] = {5, 2,100, 6, 10, 2};
    vector<int> vec(a, a + 6);
    int num = solution.numSubarrayProductLessThanK(vec, 100);
    cout << num << endl;
}