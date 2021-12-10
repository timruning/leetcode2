//
// Created by fengsong on 2021/12/9.
//
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {
        int result = 0;
        int a = 0;
        int b = 0;
        for (int i = 0; i < nums.size(); i++) {
            result = max(a+nums[i],b);
            a = b;
            b= result;
        }
        return result;
    }
};