//
// Created by 宋峰 on 2018/9/20.
//

#include <iostream>
#include <vector>
#include "../algorithm/matrix_saddle_point.cpp"

using namespace std;

int main() {
    int a[5][5] = {
            {11, 3,  5,  6,  9},
            {12, 4,  7,  8,  10},
            {10, 5,  6,  9,  11},
            {8,  6,  4,  7,  2},
            {15, 10, 11, 20, 25}
    };
    vector<vector<int>> vec;
    for (int i = 0; i < 5; i++) {
        vector<int> tmp(a[i], a[i] + 5);
        vec.push_back(tmp);
    }
    vector<pair<int, int>> result = findSaddle_Point(vec);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i].first << "\t" << result[i].second << "\t" << vec[result[i].first][result[i].second] << endl;
    }

}
