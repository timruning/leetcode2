//
// Created by 宋峰 on 2021/2/22.
//
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        int result = 0;
        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < m - 2; j++) {
                vector<int> vec(9, 0);
                for (int a = 0; a < 3; a++) {
                    for (int b = 0; b < 3; b++) {
                        if (grid[i + a][j + b] > 0 && grid[i + a][j + b] < 10) {
                            vec[grid[i + a][j + b]-1] += 1;
                        }
                    }
                }
                bool flag= false;

                for(auto v:vec){
                    if(v!=1){
                        flag=true;
                    }
                }
                if(flag)
                    continue;
                int sum = grid[i][j] + grid[i][j + 1] + grid[i][j + 2];

                if (grid[i + 1][j] + grid[i + 1][j + 1] + grid[i + 1][j + 2] != sum) {
                    continue;
                }
                if (grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2] != sum) {
                    continue;
                }

                if (grid[i][j] + grid[i + 1][j] + grid[i + 2][j] != sum) {
                    continue;
                }

                if (grid[i][j + 1] + grid[i + 1][j + 1] + grid[i + 2][j + 1] != sum) {
                    continue;
                }
                if (grid[i][j + 2] + grid[i + 1][j + 2] + grid[i + 2][j + 2] != sum) {
                    continue;
                }

                if (grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2] != sum) {
                    continue;
                }

                if (grid[i + 2][j] + grid[i + 1][j + 1] + grid[i][j + 2] != sum) {
                    continue;
                }
                result += 1;
            }
        }
        return result;
    }
};