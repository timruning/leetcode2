//
// Created by 宋峰 on 2018/9/25.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool canJump(vector<int> &nums) {
        int size = nums.size();
        vector<int> mem(size, -1);
        mem[0] = 0;
        int max = nums[0];
        for (int i = 0; i < size; i++) {
            if (i < max) {
                mem[i] = i;
            }
            if (mem[i] != -1) {
                max = (i + nums[i])>max?(i+nums[i]):max;
                if (max >= size-1)
                    return true;
                mem[max] = i;
            } else {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
//    int a[] = {2, 3, 1, 1, 4};
    int a[] = {3,0,8,2,0,0,1};
    vector<int> vec(a, a + sizeof(a) / sizeof(int));
    bool result = solution.canJump(vec);
    if (result) {
        cout << "hello" << endl;
    } else {
        cout << "bye" << endl;
    }
}