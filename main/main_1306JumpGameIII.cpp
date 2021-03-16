//
// Created by 宋峰 on 2021/3/15.
//

#include <vector>
#include <iostream>
#include "../medium/1306JumpGameIII.cpp"

using namespace std;
int main(){
    vector<int> vec({4,2,3,0,3,1,2});
    Solution sol;
    bool n = sol.canReach(vec,5);
    cout<< n<< endl;

}