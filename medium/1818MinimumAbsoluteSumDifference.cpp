//
// Created by 宋峰 on 2021/12/3.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int bi_search(vector<int> vec, int x, int begin, int end) {
        if (vec[begin] >= x) {
            return 0;
        }
        while (begin < end) {
            int mid = (begin + end) / 2;
            if (vec[mid] <= x) {
                if (mid + 1 >= end || vec[mid + 1] > x) {
                    return mid;
                } else {
                    begin = mid;
                }
            } else {
                end = mid;
            }
        }
        return 0;
    }

    int minAbsoluteSumDiff(vector<int> &nums1, vector<int> &nums2) {
        vector<int> sort1(nums1.begin(), nums1.end());
        sort(sort1.begin(), sort1.end());
        const int mod = 1e9 + 7;
        using ll = long long;
        int result = 0;
        ll max = 0;
        for (int i = 0; i < nums1.size(); i++) {
            ll x = abs(nums1[i] - nums2[i]);
            result = (result + x) % mod;
            int l = 0;
            int r = sort1.size();
            int index = 0;
            while (l < r) {
                int mid = (l + r) / 2;
                if (sort1[mid] <= nums2[i]) {
                    if (mid + 1 >= r || sort1[mid + 1] >= nums2[i]) {
                        index = mid;
                        break;
                    } else {
                        l = mid;
                    }
                } else {
                    r = mid;
                }
            }
            ll t = abs(sort1[index] - nums2[i]);
            if (x - t > max) {
                max = x - t;
            }
            ll t1 = abs(sort1[index + 1] - nums2[i]);
            if (index + 1 < sort1.size() && x - t1 > max) {
                max = x - t1;
            }
        }
        result = (result - max) % mod;
        return result;
    }
};