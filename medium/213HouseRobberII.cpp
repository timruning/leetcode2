//
// Created by fengsong on 2021/12/9.
//

#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int a = 0;
        int b = 0;
        int result1 = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            result1 = max(a + nums[i], b);
            a = b;
            b = result1;
        }

        a = 0;
        b = 0;
        int result2 = 0;
        for (int i = 1; i < nums.size(); i++) {
            result2 = max(a + nums[i], b);
            a = b;
            b = result2;
        }
        return max(result1, result2);
    }
};