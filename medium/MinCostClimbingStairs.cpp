//
// Created by timruning on 18-5-11.
//

#include "../import_iostream.h"

class MinCostClimbingStairs {
public:
    int minCostClimbingStairs(vector<int> &cost) {
        vector<int> tmp(cost.size());
        tmp[0] = cost[0];
        tmp[1] = cost[1];
        for (int i = 2; i < cost.size(); i++) {
            int min = tmp[i - 1] < tmp[i - 2] ? tmp[i - 1] : tmp[i - 2];
            tmp[i] = min + cost[i];
        }
        return tmp[tmp.size() - 1] < tmp[tmp.size() - 2] ? tmp[tmp.size() - 1] : tmp[tmp.size() - 2];
    }
};