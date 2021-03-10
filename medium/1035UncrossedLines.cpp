//
// Created by 宋峰 on 2021/3/8.
//
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxUncrossedLines(vector<int> &A, vector<int> &B) {

        vector<vector<int>> mem(A.size() + 1, vector<int>(B.size() + 1, 0));

        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < B.size(); j++) {

                if (A[i] == B[j]) {
                    mem[i + 1][j + 1] = mem[i][j] + 1 > mem[i + 1][j] ? mem[i][j] + 1 : mem[i + 1][j];
                    mem[i + 1][j + 1] = mem[i + 1][j + 1] > mem[i][j+1] ? mem[i + 1][j + 1] : mem[i][j+1];
                } else {
                    mem[i + 1][j + 1] = mem[i + 1][j] > mem[i ][j+1] ? mem[i + 1][j] : mem[i ][j+1];
                }
            }
        }
        return mem[A.size()][B.size()];
    }
};