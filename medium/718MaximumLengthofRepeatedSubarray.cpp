//
// Created by 宋峰 on 2018/10/9.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int numa=A.size();
        int numb=B.size();
        vector<vector<int>> mem;
        for(int i=0;i<numa;i++){
            vector<int> tmp(numb,0);
            mem.push_back(tmp);
        }
        if(numa==0 ||numb==0)
            return 0;
        int max=0;
        for(int i=0;i<numa;i++){
            for(int j=0;j<numb;j++){
                if(A[i]==B[j]){
                    if(i==0 || j==0){
                        mem[i][j]=1;
                    }else{
                        mem[i][j]=1+mem[i-1][j-1];
                    }
                    if(mem[i][j]>max)
                        max=mem[i][j];
                }
            }
        }
        return max;
    }
};

int main(){
    Solution solution;
    int a[]={1,2,3,2,1};
    vector<int> vec_a (a,a+ sizeof(a)/ sizeof(int));
    int b[]={3,2,1,4,3};
    vector<int> vec_b (b,b+ sizeof(b)/ sizeof(int));
    int result=solution.findLength(vec_a,vec_b);
    cout<<result<<endl;
}