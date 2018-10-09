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
        //record the coordinate of all the '1' in A
        //record the coordinate of all the '1' in B
        vector<pair<int,int>> A1;
        vector<pair<int,int>> B1;
        for(int r=0;r<A.size();r++)
            for(int c=0;c<A[0].size();c++){
                if(A[r][c]==1)  A1.push_back(pair<int,int>(r,c));
                if(B[r][c]==1)  B1.push_back(pair<int,int>(r,c));
            }


        //Step1: For all '1' in A, find all the movements which we can get score from it.
        unordered_map<int, int> ht;
        for(auto ca:A1){
            for(auto cb:B1){
                int hashkey=(ca.first-cb.first)*100
                            +(ca.second-cb.second);
                ht[hashkey]++;
            }
        }

        //Step 2: For all movements found in step1, find the one who scores most. Return the score.
        int ans=0;
        for(auto it:ht){
            ans = max(ans,it.second);
        }

        return ans;
    }
};
int main(){

}