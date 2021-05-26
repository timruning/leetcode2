//
// Created by 宋峰 on 2021/3/30.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int check(vector<int> vec, int first) {
        int result = 0;
        int num0=0;
        int num1=0;
        for (int i = 0; i < vec.size(); i++) {
            if(vec[i]==0){
                num0++;
            }else{
                num1++;
            }
            if (i % 2 == 0 && vec[i] == 1 - first) {
                result++;
            } else if (i % 2 != 0 && vec[i] == first) {
                result++;
            }
        }
        if(num0-num1>=2 || num1-num0>=2){
            return 1;
        }
        return result;
    }

    bool check2(vector<int> vec1,vector<int> vec2){
        if(vec1.size()!=vec2.size()){
            return false;
        }
        if(vec1[0]!=vec2[0]){
            for(int i=1;i<vec1.size();i++){
                if(vec1[i]==vec2[i]){
                    return false;
                }
            }
        }else{
            for(int i=1;i<vec1.size();i++){
                if(vec1[i]!=vec2[i]){
                    return false;
                }
            }
        }
        return true;
    }

    int movesToChessboard(vector<vector<int>> &board) {
        int row = -1;
        int tmp = check(board[0], 0);
        if (tmp % 2 == 0) {
            row = tmp / 2;
        }
        tmp = check(board[0], 1);
        if (tmp % 2 == 0 && (row == -1 || tmp / 2 < row)) {
            row = tmp / 2;
        }
        if (row == -1) {
            return row;
        }
        vector<int> vec(board.size(), 0);
        for (int i = 0; i < board.size(); i++) {
            vec[i] = board[i][0];
        }
        int col = -1;
        tmp = check(vec, 0);
        if (tmp % 2 == 0) {
            col = tmp / 2;
        }
        tmp = check(vec, 1);
        if (tmp % 2 == 0 && (col == -1 || tmp / 2 < col)) {
            col = tmp / 2;
        }
        if (col == -1) {
            return col;
        }
        for(int i=1;i<board.size();i++){
            bool flag = check2(board[i-1],board[i]);
            if(flag== false){
                return -1;
            }
        }

        return row + col;
    }
};