//
// Created by 宋峰 on 2020/4/11.
//

#include "../import_iostream.h"

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int  m = mat.size();
        int  n= mat[0].size();
        vector<vector<int>>t(m+1,vector<int>(n+1,0));
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                t[i][j]=mat[i-1][j-1]+t[i-1][j]+t[i][j-1]-t[i-1][j-1];
            }
        }
        vector<vector<int>>ans(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int r1 = max(0, i - K) + 1;
                int c1 = max(0, j - K) + 1;
                int r2 = min(m, i + K + 1);
                int c2 = min(n, j + K + 1);
                ans[i][j] = t[r2][c2] - t[r1 - 1][c2] - t[r2][c1 - 1] + t[r1 - 1][c1 - 1];
            }
        }
        return ans;
    }
};