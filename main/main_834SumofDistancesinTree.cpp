//
// Created by 宋峰 on 2021/4/15.
//

#include <vector>
#include <iostream>
#include "../medium/834SumofDistancesinTree.cpp"

using namespace std;

int main() {
    Solution sol;
    vector<vector<int>> vec({{2, 0},
                             {3, 1},
                             {2, 1}});
    vector<int> result = sol.sumOfDistancesInTree(4, vec);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
}