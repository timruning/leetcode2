//
// Created by 宋峰 on 2021/12/1.
//
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        if (k == 0) {
            return false;
        }
        unordered_map<long long, long long> mem;
        if (t == 0) {
            for (int i = 0; i < nums.size(); i++) {
                if (mem.find(nums[i]) != mem.end()) {
                    return true;
                }
                if (i >= k) {
                    mem.erase(nums[i - k]);
                }
                mem[nums[i]] = i;
            }
        } else {
            for (int i = 0; i < nums.size(); i++) {
                int n = nums[i] / t;
                if (mem.find(n) != mem.end()) {
                    long long x = (long long) mem[n] - (long long) nums[i];
                    if (abs(x) <= t) {
                        return true;
                    }
                }

                if (mem.find((long long)n - 1) != mem.end()) {
                    long long x = (long long) mem[(long long) n - 1] - (long long) nums[i];
                    if (abs(x) <= t) {
                        return true;
                    }
                }

                if (mem.find((long long)n + 1) != mem.end()) {
                    long long x = (long long) mem[(long long) n + 1] - (long long) nums[i];
                    if (abs(x) <= t) {
                        return true;
                    }
                }

                if (i >= k && mem[nums[i - k] / t] == nums[i - k]) {
                    mem.erase(nums[i - k] / t);
                }
                mem[n] = nums[i];
            }
        }


        return false;
    }
};