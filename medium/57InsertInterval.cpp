//
// Created by 宋峰 on 2019/4/10.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
        vector<vector<int>> result;
        int index = 0;
        for (int i = 0; i < intervals.size(); i++) {
            if (index == 0) {
                if (intervals[i][0] > newInterval[1]) {
                    result.push_back(vector<int>(newInterval));
                    result.push_back(vector<int>(intervals[i]));
                    index = 1;
                } else if (intervals[i][1] < newInterval[0]) {
                    result.push_back(vector<int>(intervals[i]));
                } else {
                    int a = min(intervals[i][0], newInterval[0]);
                    int b = max(intervals[i][1], newInterval[1]);
                    result.push_back(vector<int>({a, b}));
                    index = 1;
                }
            } else {
                if (result[result.size() - 1][1] < intervals[i][0]) {
                    result.push_back(intervals[i]);
                } else if (result[result.size() - 1][1] < intervals[i][1]) {
                    result[result.size() - 1] = vector<int>({result[result.size() - 1][0], intervals[i][1]});
                } else {
                    continue;
                }
            }
        }
        if (index == 0) {
            result.push_back(newInterval);
        }
        return result;
    }
};