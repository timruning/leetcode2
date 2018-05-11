//
// Created by timruning on 18-5-11.
//
#include "../import_iostream.h"

class NumArray {
public:
    vector<int> sumIndex;

    NumArray(vector<int> nums) {
        sumIndex.push_back(0);
        for (int i = 0; i < nums.size(); i++) {
            int sum = sumIndex[i] + nums[i];
            sumIndex.push_back(sum);
        }
    }

    int sumRange(int i, int j) {
        return sumIndex[j + 1] - sumIndex[i];
    }
};