//
//  main_1590MakeSumDivisiblebyP.cpp
//  leet_code_xcode
//
//  Created by 宋峰 on 2021/2/19.
//

#include <stdio.h>
#include "../medium/1590MakeSumDivisiblebyP.cpp"
#include <iostream>
#include <vector>
using namespace std;

int main(){
    Solution sol;
    vector<int> vec({8,32,31,18,34,20,21,13,1,27,23,22,11,15,30,4,2});
    int x = sol.minSubarray(vec, 148);
    cout<< x <<endl;
}
