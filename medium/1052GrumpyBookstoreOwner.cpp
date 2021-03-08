//
// Created by 宋峰 on 2021/3/5.
//
#include <vector>

using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int X) {
        int sum_x;
        int sum_x_p;
        int total = 0;
        int max_sum_x = 0;

        for (int i = 0; i < customers.size(); i++) {
            total += ((1 - grumpy[i]) * customers[i]);
            sum_x += customers[i];
            sum_x_p += ((1 - grumpy[i]) * customers[i]);
            if (i >= X) {
                sum_x -= customers[i - 5];
                sum_x_p -= ((1 - grumpy[i - 5]) * customers[i - 5]);
            }
            if (sum_x - sum_x_p > max_sum_x) {
                max_sum_x = sum_x - sum_x_p;
            }
        }

        return total + max_sum_x;
    }
};