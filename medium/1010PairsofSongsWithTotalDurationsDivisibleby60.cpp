//
// Created by 宋峰 on 2021/2/23.
//
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numPairsDivisibleBy60(vector<int> &time) {
        unordered_map<int, int> map;
        for (int i = 0; i < time.size(); i++) {
            int x = time[i] % 60;
            if (map.find(x) == map.end()) {
                map[x] = 1;
            } else {
                map[x] += 1;
            }
        }

        int result = 0;
        if (map.find(0) != map.end()) {
            result += (map[0] - 1) * map[0] / 2;
        }

        if (map.find(30) != map.end()) {
            result += (map[30] - 1) * map[30] / 2;
        }

        for (auto k:map) {
            if (k.first!=0 && k.first!=30 && k.second != 0 && map.find(60 - k.first) != map.end()) {
                result += k.second * map[60 - k.first];
                map[k.first] = 0;
                map[60 - k.first] = 0;
            }
        }
        return result;
    }
};