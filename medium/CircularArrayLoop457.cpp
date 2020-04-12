//
// Created by timruning on 2020/4/11.
//
#include "../import_iostream.h"

class Solution {
public:
    int mod(int a, int b) {
        int t = a % b;
        if (t < 0) {
            t = t + b;
        }
        return t;
    }

    bool circularArrayLoop(vector<int> &nums) {
        int index = 0;
        vector<int> flag(nums.size(), 0);
        bool result = false;
        while (index < nums.size()) {
            if (flag[index] != 0) {
                index += 1;
            } else {
                int fast = index;
                int slow = index;
                bool dir = nums[fast] > 0;
                while (true) {
                    flag[fast] = 1;
                    flag[slow] = 1;
                    if (dir) {
                        int old = slow;
                        slow = mod(slow + nums[slow], nums.size());
                        if (dir != nums[slow] > 0 || slow == old) {
                            break;
                        }
                        old = fast;
                        fast = mod(fast + nums[fast], nums.size());
                        flag[fast] = 1;
                        if (dir != nums[fast] > 0 || fast == old) {
                            break;
                        }
                        old = fast;
                        fast = mod(fast + nums[fast], nums.size());
                        if (dir != nums[fast] > 0 || fast == old) {
                            break;
                        }
                    } else {
                        int old = slow;
                        slow = mod(slow + nums[slow], nums.size());
                        if (dir != nums[slow] > 0 || slow == old) {
                            break;
                        }
                        old = fast;
                        fast = mod(fast + nums[fast], nums.size());
                        flag[fast] = 1;
                        if (dir != nums[fast] > 0 || fast == old) {
                            break;
                        }
                        old = fast;
                        fast = mod(fast + nums[fast], nums.size());
                        if (dir != nums[fast] > 0 || fast == old) {
                            break;
                        }
                    }
                    if (slow == fast) {
                        return true;
                    }
                }
            }
        }
        return result;
    }
};
