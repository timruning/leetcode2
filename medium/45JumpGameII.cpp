//
// Created by 宋峰 on 2021/3/15.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int jump2(vector<int>& nums) {
        int step=0;
        int result = 0;
        int maxi = 0;
        int i=0;

        while(i<nums.size()){
            if(result>=nums.size()-1){
                break;
            }

            while(i<=maxi && i<nums.size()){
                result = max(i+nums[i],result);
                i+=1;
            }
            step+=1;
            maxi = result;

        }

        return step;
    }
    int jump(vector<int> &nums) {
        vector<int> steps(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[i]; j++) {
                if(i+j+1>=nums.size()){
                    break;
                }
                if(steps[i+j+1]==0){
                    steps[i+j+1] = steps[i]+1;
                }else{
                    steps[i+j+1] =min(steps[i+j+1],steps[i]+1);
                }
            }
        }
        return steps[steps.size()-1];
    }
};