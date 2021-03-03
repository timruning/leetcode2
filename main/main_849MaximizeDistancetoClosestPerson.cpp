//
// Created by 宋峰 on 2021/3/2.
//

#include <vector>
#include <iostream>
#include "../medium/849MaximizeDistancetoClosestPerson.cpp"
using namespace std;
int main(){
    vector<int> vec({1,0,0,0,1,0,1});
    Solution sol;
    int n = sol.maxDistToClosest(vec);
    cout<<n<<endl;
}