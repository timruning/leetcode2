//
// Created by 宋峰 on 2021/3/17.
//

#include <vector>
#include <iostream>
#include "../medium/719FindKthSmallestPairDistance.cpp"

using namespace std;

int main() {
    vector<int> vec({1, 2, 3, 4, 5, 6, 7});
    Solution sol;
    int n = sol.smallestDistancePair(vec, 20);
    cout << n << endl;
}