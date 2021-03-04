//
// Created by 宋峰 on 2021/3/3.
//

#include <vector>
#include <iostream>
#include "../medium/1583CountUnhappyFriends.cpp"

using namespace std;

/**
 * 4
{{1,2,3},{3,2,0},{3,1,0},{1,2,0}
{{0,1},{2,3}
 * */
int main() {
    int n = 4;
    vector<vector<int>> preferences(
            {{1,3,2},{0,2,3},{3,1,0},{2,0,1}}
    );
    vector<vector<int>> pairs({{2,1},{3,0}});
    Solution sol;
    int t = sol.unhappyFriends(n, preferences, pairs);
    cout << t << endl;

}