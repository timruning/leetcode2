//
// Created by fengsong on 2021/12/9.
//
#include <vector>
#include <math.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    static bool comp(pair<int, int> a, pair<int, int> b) {
        return a.first > b.first;
    }

    int deleteAndEarn(vector<int> &nums) {
        unordered_map<int, int> mem;
        for (auto v: nums) {
            mem[v] += 1;
        }
        vector<pair<int, int>> vec(mem.begin(), mem.end());
        sort(vec.begin(), vec.end(), comp);
        int result = 0;
        int a = 0;
        int b = 0;
        for (int i = 0; i < vec.size(); i++) {
            if (i >= 1 && vec[i].first != vec[i - 1].first - 1) {
                a = result;
                b = result;
            }
            result = max(a + vec[i].first * vec[i].second, b);
            a = b;
            b = result;
        }
        return result;
    }
};