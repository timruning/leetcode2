//
// Created by 宋峰 on 2021/3/17.
//
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target) {
        vector<vector<int>> mem(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));

        int result = 0;

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                mem[i + 1][j + 1] = matrix[i][j] + mem[i + 1][j] + mem[i][j + 1] - mem[i][j];
                for (int p = 0; p < i; p++) {
                    for (int q = 0; q < j; q++) {
                        if (mem[i + 1][j + 1] - mem[i + 1][q] - mem[p][j + 1] + mem[p][q]==target){
                            result+=1;
                        }
                    }
                }
            }
        }

        return result;
    }
};