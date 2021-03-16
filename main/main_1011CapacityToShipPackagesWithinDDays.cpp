//
// Created by 宋峰 on 2021/3/15.
//

#include <vector>
#include <iostream>
#include "../medium/1011CapacityToShipPackagesWithinDDays.cpp"
using namespace std;

int main(){
    Solution sol;
    vector<int> vec({1,2,3,1,1});
    int t = sol.shipWithinDays(vec,4);
    cout<<t<<endl;
}