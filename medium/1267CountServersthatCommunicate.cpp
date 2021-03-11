//
// Created by 宋峰 on 2021/3/10.
//
#include <vector>

using namespace std;

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        vector<int> col(grid.size(),0);
        vector<int> rol(grid[0].size(),0);

        for(int i=0;i<grid.size();i++){
            int c=0;
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    c+=1;
                    rol[j]+=1;
                }
            }
            col[i]=c;
        }
        int  count =0;
        for(int i=0;i<grid.size();i++){

            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    if(col[i]>1 || rol[j]>1){
                        count+=1;
                    }
                }
            }

        }

        return count;

    }
};