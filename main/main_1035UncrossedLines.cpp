//
// Created by 宋峰 on 2021/3/8.
//

#include <vector>
#include <iostream>
#include "../medium/1035UncrossedLines.cpp"

using namespace std;

int main() {
    vector<int> A({1, 4, 2});
    vector<int> B({1, 2, 4});
    Solution sol;
    int n = sol.maxUncrossedLines(A, B);
    cout << n << endl;


}