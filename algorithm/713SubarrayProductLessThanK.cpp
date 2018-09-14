//
// Created by 宋峰 on 2018/9/1.
//
#include <vector>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k) {
        int result = 0;
        int size = nums.size();
        if (size <= 0) {
            return result;
        }
        vector<int> product(size + 1, 1);
        vector<int> current_num(size + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= k) {
                product[i + 1] = nums[i];
                current_num[i+1]=1;
                continue;
            }
            int tmp = product[i] * nums[i];
            if (tmp < k) {
                current_num[i + 1] = current_num[i] + 1;
            } else {
                int begin = i - current_num[i];
                if (begin < 0) {
                    continue;
                }
                while (begin < i) {
                    tmp = tmp / nums[begin];
                    if (tmp < k) {
                        current_num[i + 1] = i - begin;
                        break;
                    }
                    begin+=1;
                }
            }
            product[i+1]=tmp;
        }
        for(int i=0;i<size+1;i++){
            if(product[i]<k)
                result+=current_num[i];
        }
        return result;
    }
};