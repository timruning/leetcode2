//
// Created by 宋峰 on 2021/3/25.
//

#include <vector>
#include <iostream>

#include "../medium/42TrappingRainWater.cpp"
using namespace std;
int main(){
    vector<int> vec({5,4,1,2});
    Solution sol;
    int n = sol.trap(vec);
    cout<<n<<endl;
}