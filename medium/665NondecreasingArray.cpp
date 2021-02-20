//
//  665NondecreasingArray.cpp
//  leet_code_xcode
//
//  Created by 宋峰 on 2021/2/18.
//

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if(nums.size()<=1){
            return true;
        }
        int count=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                
                if(i==1 || nums[i-2] <= nums[i]){
                    nums[i-1]=nums[i];
                    count++;
                }else{
                    nums[i]=nums[i-1];
                    count++;
                }
            }
            cout<< i << endl;
        }
        if(count>1){
            return false;
        }
        return true;
    }
};
