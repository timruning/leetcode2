//
// Created by 宋峰 on 2021/4/7.
//

#include <vector>
#include <iostream>
#include "../medium/1499MaxValueofEquation.cpp"

using namespace std;

int main() {
    vector<vector<int>> vec({{-19, 1},
                             {-18, -13},
                             {-17, -12},
                             {-14, -14},
                             {-8,  -9},
                             {-6,  16},
                             {-2,  -4},
                             {2,   15},
                             {4,   19},
                             {5,   -9},
                             {6,   20},
                             {7,   -17},
                             {16,  3}});
    Solution sol;
    int n = sol.findMaxValueOfEquation(vec, 5);
    cout << n << endl;
}
