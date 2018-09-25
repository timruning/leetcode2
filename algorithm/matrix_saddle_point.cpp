//
// Created by 宋峰 on 2018/9/20.
//

#include <vector>
using namespace std;

vector<pair<int,int> > findSaddle_Point(vector<vector<int> >& matrix){
    vector<pair<int,int> > result;

    int row=matrix.size();
    int col=matrix[0].size();

    vector<int> maxRow(row,0);  //行最大
    vector<int> minRow(row,0);  //行最小
    vector<int> maxCol(col,0);  //列最大
    vector<int> minCol(col,0);  //列最小

    for(int i=0;i<row;i++){
        int max_row_i=0;  //i 行最大的列号
        int min_row_i=0;  //i 行最小的列号
        for(int j=0;j<col;j++){
            if(matrix[i][j]>matrix[i][max_row_i]){
                max_row_i=j;
            }
            if(matrix[i][j]<matrix[i][min_row_i]){
                min_row_i=j;
            }
            if(matrix[i][j]>matrix[maxCol[j]][j]){
                maxCol[j]=i;
            }
            if(matrix[i][j]<matrix[minCol[j]][j]){
                minCol[j]=i;
            }
        }
        maxRow[i]=max_row_i;
        minRow[i]=min_row_i;
    }

    for(int i=0;i<row;i++){
        if(minCol[maxRow[i]]==i){
            result.push_back(pair<int,int>(i,maxRow[i]));
        }
        if(maxCol[minRow[i]]==i){
            result.push_back(pair<int,int>(i,minRow[i]));
        }
    }

    return result;
}