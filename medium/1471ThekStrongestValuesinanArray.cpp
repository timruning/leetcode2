//
// Created by 宋峰 on 2021/3/11.
//
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> getStrongest(vector<int> &arr, int k) {
        vector<int> result;
        sort(arr.begin(), arr.end());
        int m = (arr.size() - 1) / 2;

        for (int i = 0, j = arr.size() - 1; i < j && i < arr.size() && j >= 0;) {
            if (arr[m] - arr[i] > arr[j] - arr[m]) {
                result.push_back(arr[i]);
                i++;
            } else if (arr[m] - arr[i] <= arr[j] - arr[m]) {
                result.push_back(arr[j]);
                j--;
            }
            if (result.size() == k) {
                break;
            }
        }
        return result;
    }
};