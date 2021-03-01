//
// Created by 宋峰 on 2021/2/23.
//

#include <vector>
#include <iostream>
#include "../medium/1010PairsofSongsWithTotalDurationsDivisibleby60.cpp"
using namespace std;

int main(){
    Solution sol;
    vector<int> vec({30,20,150,100,40});
    int t = sol.numPairsDivisibleBy60(vec);
    cout<<t<<endl;
}
