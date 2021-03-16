//
// Created by 宋峰 on 2021/3/12.
//

#include <vector>

using namespace std;

class Solution {
public:
    bool check(vector<int> &weights, int D, int cap) {
        int t = 0;
        int sum = 0;
        for (int i = 0; i < weights.size(); i++) {
            if(weights[i]>cap){
                return false;
            }
            if (sum + weights[i] > cap) {
                sum = weights[i];
                t++;
            } else {
                sum += weights[i];
            }
        }
        t += 1;
        if (t <= D) {
            return true;
        } else {
            return false;
        }
    }

    int shipWithinDays(vector<int> &weights, int D) {
        int sum = 0;
        for (int i = 0; i < weights.size(); i++) {
            sum += weights[i];
        }
        int result = sum / D;
        int begin = 1;
        int end = sum;
        while (result < end) {
            if (check(weights, D, result)) {
                if (check(weights, D, result - 1)) {
                    end = result;
                    result = (begin + result) / 2;
                } else {
                    return result;
                }
            } else {
                begin = result;
                result = (result + end) / 2;
            }
        }

        return result;
    }
};