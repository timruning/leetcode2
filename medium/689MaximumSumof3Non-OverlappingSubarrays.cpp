//
// Created by 宋峰 on 2021/3/26.
//

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k) {
        vector<int> sums(nums.size(), 0);
        sums[nums.size() - 1] = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i >= 0; i--) {
            sums[i] = sums[i + 1] + nums[i];
            if (i < nums.size() - k) {
                sums[i] = sums[i] - nums[i + k];
            }
        }

        vector<vector<int>> mem(sums.size() - k + 1, {0, k, 2 * k});

        for (int i = 1; i < mem.size(); i++) {
            if (sums[i] > sums[mem[i - 1][0]]) {
                mem[i][0] = i;
            } else {
                mem[i][0] = mem[i - 1][0];
            }
            if(i>16){
                int t =1;
                t=t+1;
            }
            if (i > k) {
                int index2= i;
                int index1 = mem[i-k][0];
                int indexa2= mem[i - 1][1];
                int indexa1 = mem[mem[i - 1][1]-k][0];
                if (sums[index2] + sums[index1] > sums[indexa2] + sums[indexa1]) {
                    mem[i][1] = i;
                } else {
                    mem[i][1] = mem[i - 1][1];
                }
            }
            if (i > 2 * k) {
                int index3 = i;
                int index2 = mem[i - k][1];
                int index1 = mem[mem[i - k][1] - k][0];
                int indexa3 = mem[i - 1][2];
                int indexa2 = mem[mem[i - 1][2] - k][1];
                int indexa1 = mem[mem[mem[i - 1][2] - k][1] - k][0];

                if (sums[index1] + sums[index2] + sums[index3] >
                    sums[indexa1] + sums[indexa2] + sums[indexa3]){
                    mem[i][2] = i;
                }
                else {
                    mem[i][2] = mem[i - 1][2];
                }
            }
        }
        int i3 = mem[mem.size() - 1][2];
        int i2 = mem[mem[mem.size() - 1][2] - k][1];
        int i1 = mem[mem[mem[mem.size() - 1][2] - k][1] - k][0];
        return vector<int>({i1, i2, i3});
    }
};