//
// Created by 宋峰 on 2018/10/9.
//

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<pair<int,int>> A_1;
        for(int i=0;i<A.size();i++){
            for(int j=0;j<A[i].size();j++){
                if(A[i][j]==1){
                    A_1.push_back(pair<int,int>(i,j));
                }
            }
        }
        vector<pair<int,int>> B_1;
        for(int i=0;i<B.size();i++){
            for(int j=0;j<B[i].size();j++){
                if(B[i][j]==1){
                    B_1.push_back(pair<int,int>(i,j));
                }
            }
        }

        int  result =0 ;
        unordered_map<int,int> map;
        for(int i=0;i<A_1.size();i++){
            for(int j=0;j<B_1.size();j++){
                int key= (A_1[i].first-B_1[j].first)*10000 + (A_1[i].second-B_1[j].second);
                if(map.find(key)==map.end()){
                    map[key]=1;
                }else{
                    map[key]+=1;
                }
                if(map[key]>result){
                    result=map[key];
                }
            }
        }

        return result;

    }
};