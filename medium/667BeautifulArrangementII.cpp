//
// Created by 宋峰 on 2021/3/4.
//
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> result;
        result.push_back(1);
        int mi = 2;
        int ma = n;
        bool flag = true;
        for (int i = 1; i < k; i++) {
            if (flag) {
                result.push_back(ma);
                flag = false;
                ma--;
            } else {
                result.push_back(mi);
                flag = true;
                mi++;
            }


        }
        if (flag) {
            for (int i = mi; i <= ma; i++) {
                result.push_back(i);
            }
        } else {
            for (int i = ma; i >=mi; i--) {
                result.push_back(i);
            }
        }
        return result;
    }
};