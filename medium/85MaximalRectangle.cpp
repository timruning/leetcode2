//
// Created by 宋峰 on 2021/11/30.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        int a = matrix.size();
        int b = matrix[0].size();
        pair<int, int> max(0, 0);
        vector<vector<int>> mem(a, vector<int>(b, 0));
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                if (matrix[i][j] == '0') {
                    mem[i][j] = 0;
                } else {
                    if (j == 0) {
                        mem[i][j] = 1;
                    } else {
                        mem[i][j] = mem[i][j - 1] + 1;;
                    }
                }
            }
        }

    }
};