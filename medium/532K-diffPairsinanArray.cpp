//
//  1590MakeSumDivisiblebyP.cpp
//  leet_code_xcode
//
//  Created by 宋峰 on 2021/2/19.
//


#include <stdio.h>
#include <vector>
#include <iostream>
#include <unordered_map>
//#include <math.h>

using namespace std;

class Solution {
public:
    int findPairs(vector<int> &nums, int k) {
        int result = 0;
        unordered_map<int, pair<int, int>> map;
        for (int i = 0; i < nums.size(); i++) {
            int a = nums[i] - k;
            int b = nums[i] + k;
            int first = 0;
            int second = 0;
            if (map.find(a) != map.end()) {
                if (map[a].second != 1) {
                    result += 1;
                    map[a].second = 1;
                }
                first = 1;
                if(k==0){
                    second=1;
                }
            }
            if (map.find(b) != map.end() && k != 0) {
                if (map[b].first != 1) {
                    result += 1;
                    map[b].first = 1;
                }
                second = 1;
            }
            map[nums[i]] = pair<int, int>(first, second);
        }

        return result;
    }
};