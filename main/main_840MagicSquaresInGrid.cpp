//
// Created by 宋峰 on 2021/2/22.
//

#include <vector>
#include <iostream>
#include "../medium/840MagicSquaresInGrid.cpp"

using namespace std;

int main() {
    vector<vector<int>> vec({{4, 3, 8, 4},
                             {9, 5, 1, 9},
                             {2, 7, 6, 2}});
    Solution sol;
    int n = sol.numMagicSquaresInside(vec);
    cout << n << endl;
}