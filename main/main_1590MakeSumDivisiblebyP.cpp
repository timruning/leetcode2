//
//  main_1590MakeSumDivisiblebyP.cpp
//  leet_code_xcode
//
//  Created by 宋峰 on 2021/2/19.
//

#include <stdio.h>
#include "../algorithm/1590MakeSumDivisiblebyP.cpp"
#include <iostream>
#include <vector>
using namespace std;

int main(){
    Solution sol;
    vector<int> vec({6,5,2,3});
    int x = sol.minSubarray(vec, 9);
    cout<< x <<endl;
}
