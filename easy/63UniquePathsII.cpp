//
// Created by 宋峰 on 2018/9/25.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int num = 0;
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        vector<vector<int>> mem;
        for (int i = 0; i < row; i++) {
            vector<int> vec(col, 0);
            mem.push_back(vec);
        }
        if(obstacleGrid[0][0]==0)
            mem[0][0]=1;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(obstacleGrid[i][j]==1){
                    mem[i][j]=0;
                }else{
                    if(i==0){
                        if(j!=0)
                            mem[i][j]=mem[i][j-1];
                    }else if(j==0)
                        mem[i][j]=mem[i-1][j];
                    else{
                        mem[i][j]=mem[i-1][j]+mem[i][j-1];
                    }
                }
            }
        }
        return mem[row - 1][col - 1];
    }
};

int main() {
    int a[3][3] = {
            {0, 0, 0},
            {0, 1, 0},
            {0, 0, 0}};
    vector<vector<int>> vec;
    for(int i=0;i<3;i++){
        vector<int> tmp(a[i],a[i]+ sizeof(a[i])/ sizeof(int));
        vec.push_back(tmp);
    }
    Solution solution;
    int num=solution.uniquePathsWithObstacles(vec);
    cout<<num<<endl;
}