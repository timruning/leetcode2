//
// Created by 宋峰 on 2021/3/3.
//
#include <vector>

using namespace std;

class Solution {
public:

    int getWinner(vector<int> &arr, int k) {
        int count = 0;
        int max = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] < max) {
                count++;
            } else {
                count = 1;
                max = arr[i];
            }
            if (count == k) {
                return max;
            }
        }
        return max;
    }

    bool compare(vector<int> &arr) {
        if (arr[0] > arr[1]) {
            int tmp = arr[1];
            arr.erase(arr.begin() + 1);
            arr.push_back(tmp);
            return true;
        } else {
            int tmp = arr[0];
            arr.erase(arr.begin());
            arr.push_back(tmp);
            return false;
        }
    }

    int getWinner1(vector<int> &arr, int k) {
        int count = 0;
        while (count < k) {
            bool t = compare(arr);
            if (t) {
                count++;
            } else {

                count = 1;
            }
        }
        return arr[0];
    }
};