//
// Created by 宋峰 on 2021/3/8.
//
#include <vector>

using namespace std;

class Solution {
public:
    bool check(vector<int> &group, vector<int> &nums,int i){
        for(int j=0;j<group.size();j++){
            if(i+j>= nums.size() || group[j]!=nums[i+j]){
                return false;
            }
        }
        return true;
    }
    bool canChoose(vector<vector<int>> &groups, vector<int> &nums) {
        int t =0;
        for(int i=0;i<nums.size();i++){
            if(t>=groups.size()){
                break;
            }
            bool flag = check(groups[t],nums,i);
            if(flag){
                i+=groups[t].size();
                t++;

            }
        }
        if(t>=groups.size()){
            return true;
        }else{
            return false;
        }
    }
};