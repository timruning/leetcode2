//
// Created by 宋峰 on 2021/3/16.
//
#include <vector>

using namespace std;

class Heap {
public:
    int size = 0;
    int sum = 0;
    vector<int> mem;

    void insert(int x) {
        mem.push_back(x);
        adjust_heap1();
        size += 1;
        sum = (sum + x) % (long long)(1e9 +7);
    }

    void delete_head() {
        int tmp = mem[0];
        mem[0] = mem[mem.size() - 1];
        mem[mem.size() - 1] = tmp;
        mem.pop_back();
        sum = (sum - tmp) % (long long) (1e9 + 7);
        size -= 1;
        adjust_heap2();
    }

    void adjust_heap1() {
        int t = mem.size() - 1;
        while (t > 0) {
            int f = (t - 1) / 2;
            if (mem[f] < mem[t]) {
                int tmp = mem[f];
                mem[f] = mem[t];
                mem[t] = tmp;
                t = f;
            } else {
                break;
            }
        }
    }

    void adjust_heap2() {
        int t = 0;
        while (t < mem.size() / 2) {
            int l = t * 2 + 1;
            int r = t * 2 + 2;
            int max = t;
            if (l < mem.size() && mem[l] > mem[max]) {
                max = l;
            }
            if (r < mem.size() && mem[r] > mem[max]) {
                max = r;
            }

            if (max != t) {
                int tmp = mem[t];
                mem[t] = mem[max];
                mem[max] = tmp;
                t = max;
            } else {
                break;
            }
        }
    }
};

class Solution {
public:
    int rangeSum(vector<int> &nums, int n, int left, int right) {
        Heap h_left;
        Heap h_right;
        left -= 1;
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum = (sum + nums[j]) % (long long) (1e9 + 7);
                if (h_left.size < left || (h_left.size > 0 && h_left.mem[0] > sum)) {
                    h_left.insert(sum);
                    if (h_left.size > left) {
                        h_left.delete_head();
                    }
                }
                if (h_right.size < right || (h_right.size > 0 && h_right.mem[0] > sum)) {
                    h_right.insert(sum);
                    if (h_right.size > right) {
                        h_right.delete_head();
                    }
                }
            }
        }
        return (h_right.sum - h_left.sum) % (long long) (1e9 + 7);
    }
};