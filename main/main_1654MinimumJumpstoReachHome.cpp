//
// Created by 宋峰 on 2021/12/2.
//

#include "../medium/1654MinimumJumpstoReachHome.cpp"
#include <iostream>
#include <vector>

using namespace std;

/**
 * [8,3,16,6,12,20]
15
13
11
 */


int main() {
    vector<int> vec = {8, 3, 16, 6, 12, 20};
    int a = 15;
    int b = 13;
    int x = 11;
    Solution sol;
    int result = sol.minimumJumps(vec, a, b, x);
    cout << result << endl;
}
