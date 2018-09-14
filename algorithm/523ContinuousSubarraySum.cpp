//
// Created by 宋峰 on 2018/9/3.
//

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool find2zero(vector<int>& nums){
        for(int i=1;i<nums.size();i++){
            if(nums[i]==0 && nums[i-1]==0){
                return true;
            }
        }
        return false;
    }
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size()<2){
            return false;
        }
        if(k==0){
            return find2zero(nums);
        }
        unordered_map<int,int> index;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int t=sum%k;
            if(t==0 && i!=0){
                return true;
            }
            if(index.find(t)!=index.end()){
                auto iter=index.find(t)->second;
                if(i-iter>1){
                    return true;
                }
            }
            else{
                index.insert(pair<int,int>(t,i));
            }
        }
        return false;
    }
};