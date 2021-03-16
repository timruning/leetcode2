//
// Created by 宋峰 on 2021/3/15.
//
#include <vector>
using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<int> stack;
        vector<int> flags(arr.size(),0);

        int pre =start;
        while ((flags[pre]==0 && pre>=0 && pre<arr.size()) || stack.size()>0){
            while (flags[pre]==0 && pre>=0 && pre<arr.size() ){
                stack.push_back(pre);
                if(arr[pre]==0){
                    return true;
                }
                flags[pre]=1;
                pre=pre+arr[pre];
            }
            int tail = stack[stack.size()-1];
            stack.pop_back();
            pre = tail - arr[tail];
        }
        return false;
    }
};