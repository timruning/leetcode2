//
// Created by timruning on 18-8-28.
//
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k) {
        int result=0;
        for(int i=0;i<nums.size();i++){
            int product=nums[i];
            if(product<k){
                result+=1;
            }else{
                continue;
            }
            for(int j=i+1;j<nums.size();j++){
                product*=nums[j];
                if(product<k){
                    result+=1;
                }else{
                    break;
                }
            }
        }
        return result;
    }
};