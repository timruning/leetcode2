//
// Created by 宋峰 on 2021/3/18.
//

#include <vector>
#include <iostream>
#include "../medium/685RedundantConnectionII.cpp"

using namespace std;

int main() {
    vector<vector<int>> edges({{4,2},{1,5},{5,2},{5,3},{2,4}});
    Solution sol;
    vector<int> vec = sol.findRedundantDirectedConnection(edges);
    cout << vec[0] << " " << vec[1] << endl;
}