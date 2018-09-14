//
// Created by 宋峰 on 2018/9/3.
//

#include <iostream>
#include <vector>
#include "../algorithm/523ContinuousSubarraySum.cpp"

using namespace std;

int main() {
    int a[] = {50000000,50000000};
    vector<int> vec(a, a + 3);
    Solution solution;
    bool find = solution.checkSubarraySum(vec, 100000000);
    if (find) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
}