//
// Created by 宋峰 on 2021/12/3.
//

#include <iostream>
#include <vector>
#include "../medium/220ContainsDuplicateIII.cpp"

using namespace std;

int main() {
    vector<int> nums = {-5,5,5,5,5,15};
    int k = 6;
    int t = 6;
    Solution sol;
    cout << sol.containsNearbyAlmostDuplicate(nums, k, t) << endl;
}