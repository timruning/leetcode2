//
// Created by 宋峰 on 2021/3/10.
//
#include <vector>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int result =0;
        int old= 0;
        int now= 0;
        bool flag = true;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                now+=1;
            }else{
                result= result> now+old? result: now+old;
                old=now;
                now=0;
            }
        }
        result= result> now+old? result: now+old;
        return result;
    }
};