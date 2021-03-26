//
// Created by 宋峰 on 2021/3/25.
//
#include <vector>

using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int> &arr) {
        if (arr.size() == 0) {
            return 0;
        }
        int result = 1;
        vector<int> maxs(arr.size() + 1, arr[0]);
        int max = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] >= maxs[result]) {
                if (arr[i] > max) {
                    max = arr[i];
                }
                result++;
                maxs[result] = max;
            } else {
                while (arr[i] < maxs[result] && result >= 1) {
                    maxs[result] = max;
                    result--;
                }
                result++;
            }
        }
        return result;
    }
};
