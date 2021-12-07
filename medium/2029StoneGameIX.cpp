//
// Created by 宋峰 on 2021/12/3.
//
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool stoneGameIX(vector<int> &stones) {
        int num0;
        int num1;
        int num2;
        for (auto v:stones) {
            if (v % 3 == 0) {
                num0 += 1;
            } else if (v % 3 == 1) {
                num1 += 1;
            } else {
                num2 += 1;
            }
        }



    }
};