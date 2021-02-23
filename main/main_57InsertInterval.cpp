//
//  main_1590MakeSumDivisiblebyP.cpp
//  leet_code_xcode
//
//  Created by 宋峰 on 2021/2/19.
//

#include <stdio.h>
#include "../medium/57InsertInterval.cpp"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    Solution sol;
    vector<vector<int>> inter({{1,  2},
                               {3,  5},
                               {6,  7},
                               {8,  10},
                               {12, 16}});
    vector<int> newinter({4, 8});
    vector<vector<int>> result = sol.insert(inter, newinter);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i][0] << " " << result[i][1] << endl;
    }
}
