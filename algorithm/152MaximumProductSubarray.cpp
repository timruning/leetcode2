//
// Created by 宋峰 on 2018/8/27.
//
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int> &nums) {
        int label = -1;
        bool has = false;
        vector<int> product;
        int max;
        product.push_back(nums[0]);
        max = nums[0];
        if(nums[0]<0){
            label=0;
        }
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == 0) {
                product.push_back(0);
                has = true;
                label = -1;
            } else {
                if (product[product.size() - 1] == 0) {
                    product.push_back(nums[i]);
                    if(nums[i]<0)
                        label=i;
                    if (nums[i] > max) max = nums[i];
                } else {
                    int x = product[product.size() - 1] * nums[i];
                    if (x > max) max = x;
                    if (x < 0) {
                        if (label == -1) {
                            label = i;
                        } else {
                            int xx = x / product[label];
                            if (xx > max) max = xx;
                        }
                    }
                    product.push_back(x);
                }
            }
        }
        if (has) {
            return max > 0 ? max : 0;
        } else {
            return max;
        }
    }
};