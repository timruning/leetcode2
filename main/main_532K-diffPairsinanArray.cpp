//
// Created by 宋峰 on 2021/2/22.
//

#include <stdio.h>
#include "../medium/532K-diffPairsinanArray.cpp"
#include <iostream>
#include <vector>

using namespace std;

int main(){
    Solution sol;
    vector<int> vec({1,1,1,1,1});
    int t = sol.findPairs(vec,0);
    cout<<t<<endl;
}