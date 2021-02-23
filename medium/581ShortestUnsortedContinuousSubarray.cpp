//
// Created by 宋峰 on 2019/4/10.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> nums2(nums);
        sort(nums2.begin(),nums2.end());
        int begin = -1;
        int end = -1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=nums2[i] && begin== -1){
                begin=i;
            }

            if(nums[nums.size()-i-1] != nums2[nums.size()-i-1] && end== -1){
                end = nums.size()-i-1;
            }
            if(begin!= -1 && end!= -1){
                break;
            }
        }
        if(begin== -1 && end== -1){
            return 0;
        }else{
            return end-begin+1;
        }
    }
};