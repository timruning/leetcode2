//
//  main_1590MakeSumDivisiblebyP.cpp
//  leet_code_xcode
//
//  Created by 宋峰 on 2021/2/19.
//

#include <stdio.h>
#include "../medium/581ShortestUnsortedContinuousSubarray.cpp"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    Solution sol;
    vector<int> vec({2,6,4,8,10,9,15});
    int t = sol.findUnsortedSubarray(vec);
    cout << t << endl;
}
