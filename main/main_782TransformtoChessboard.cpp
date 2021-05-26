//
// Created by 宋峰 on 2021/3/31.
//

#include <iostream>
#include <vector>
#include "../medium/782TransformtoChessboard.cpp"

using namespace std;

int main() {
    vector<vector<int>> vec({{1, 0, 0},
                             {0, 1, 1},
                             {1, 0, 0}});

    Solution sol;
    int n = sol.movesToChessboard(vec);
    cout << n << endl;

}