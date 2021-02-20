//
//  1590MakeSumDivisiblebyP.cpp
//  leet_code_xcode
//
//  Created by 宋峰 on 2021/2/19.
//
#pragma clang diagnostic push
#pragma clang diagnostic ignored "警告名称"

#include <stdio.h>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& A, int p) {
        int n = A.size();
        getModularPrefixSum(A, n, p);
        if (A[n-1] == 0) return 0;  // The sum is already divisible by p
        int ans = n;
        
        unordered_map<int, int> prevIndex;prevIndex[0] = -1;
        // If the subarray starts from the beginning
        
        for (int i = 0; i < n; i++) {
            prevIndex[A[i]] = i;
            int diff = (A[i] - A[n-1] + p) % p;
            
            if (prevIndex.find(diff) != prevIndex.end())
                ans = min(ans, i - prevIndex[diff]);
        }

        return ans < n ? ans : -1;
    }

    void getModularPrefixSum(vector<int>& A, int n, int p) {
        A[0] %= p;
        for (int i = 1; i < n; i++) {
            A[i] += A[i-1];
            A[i] %= p;
        }
    }
    
    int minSubarray1(vector<int>& nums, int p) {
        int result = -1;
        if(nums.size()==0){
            return result;
        }
        
        unordered_map<int, int> map;
        map[0]=0;
        vector<long long> sums(nums.size()+1,0);
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            sums[i+1]=sum;
            int t = sum%p;
            if(map.find(t)==map.end()){
                map[t]=i;
            }
            if(t==0){
                result = nums.size()-i-1;
            }
        }
        
        int t =sum%p;
        if(t==0){
            return 0;
        }
        
        if(map.find(t)!=map.end() && map.find(t)->second!= nums.size()-1){
            int index =map.find(t)->second;
            result = index+1;
        }
        
        for(int i=1;i<sums.size();i++){
            for(int j=1;j<=i;j++){
                long long d = sums[i]-sums[i-j];
                if(result != -1 && j>=result){
                    break;
                }
                if(d%p==t && j!= nums.size()){
                    result=j;
                }
            }
        }
        
        return result;
    }
};
#pragma clang diagnostic pop
