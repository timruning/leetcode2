//
// Created by 宋峰 on 2021/12/8.
//
#include <vector>

using namespace std;

class Solution {
public:
    int mod = 1e9 + 7;

    int waysToSplit(vector<int> &nums) {
        vector<int> sum(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            sum[i] += sum[i - 1];
        }
        int result = 0;

        for (int i = 0; i < sum.size(); i++) {
            int left = sum[i];
            int l2min = 2 * left;
            int index = bi_search(l2min);
            int l2max = left + (sum.back() - left + 1) / 2;
            int index2 = bi_search(l2max);
            result = (result + (index2 - index)) % mod;
        }

        return result;
    }
};