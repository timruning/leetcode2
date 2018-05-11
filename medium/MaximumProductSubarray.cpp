//
// Created by timruning on 18-5-10.
//
#include "../import_iostream.h"

class MaximumProductSubarray {
public:
    int maxProduct1(vector<int> nums) {
        int falseNum = 0;

        if (nums.size() == 0) {
            return 0;
        } else if (nums.size() == 1) {
            return nums[0];
        }

        int allProduct = 1;
        int headProduct = 1;
        int tailProduct = 1;

        for (int i = 0; i < nums.size(); i++) {
            allProduct *= nums[i];
            if (nums[i] < 0) {
                falseNum += 1;
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            headProduct *= nums[i];
            if (nums[i] < 0) {
                break;
            }
        }

        for (int i = nums.size() - 1; i >= 0; i--) {
            tailProduct *= nums[i];
            if (nums[i] < 0) {
                break;
            }
        }

        if (falseNum % 2 == 0) {
            return allProduct;
        } else {
            int tmp = headProduct > tailProduct ? headProduct : tailProduct;
            return allProduct / tmp;
        }

    }

    int maxProduct(vector<int> &nums) {
        if (nums.size() == 0)
            return 0;
        else if (nums.size() == 1)
            return nums[0];
        bool findZero = false;
        int begin = 0;
        int end = 1;

        int result = nums[0];

        while (end <= nums.size()) {
            if(nums[begin]==0){

            }
            if (end == nums.size() || nums[end] == 0) {
                if (nums[end] == 0) {
                    findZero = true;
                }
                vector<int> subVec(nums.begin() + begin, nums.begin() + end);
                int max = maxProduct1(subVec);
                result = max > result ? max : result;
                begin = end + 1;
                end = begin;
            } else {
                end += 1;
            }
        }

        return result > 0 ? result : 0;
    }
};