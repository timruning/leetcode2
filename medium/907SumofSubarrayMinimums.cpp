//
// Created by 宋峰 on 2019/4/7.
//
#include <vector>

using namespace std;
class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        int sum=0;
        int size=A.size();
        int M=1e9+7;
        vector<int> a_tmp(size,0);
        vector<vector<int>> a(size,a_tmp);
        for(int i=0;i<A.size();i++){
            int min=A[i];
            for(int j=i;j<A.size();j++){
                if(A[j]<min){
                    min=A[j];
                }
                a[i][j]=min;
            }
        }
        for(int i=0;i<A.size();i++){
            for(int j=i;j<A.size();j++){
                sum=(sum+a[i][j])%M;
            }
        }
        return sum;
    }
    int sumSubarrayMins2(vector<int>& A) {
        A.push_back(0);
        int N = A.size(),res=0,M=1e9+7;
        vector<int> stk={-1};
        for(int i=0;i<N;i++) {
            while(stk.back()!=-1 && A[i]<A[stk.back()]) {
                int highest = stk.back();
                stk.pop_back();
                int l=stk.back();
                res=(0LL+res+(highest-l)*(i-highest)*A[highest])%M;
            }
            stk.push_back(i);
        }
        return res;
    }
};