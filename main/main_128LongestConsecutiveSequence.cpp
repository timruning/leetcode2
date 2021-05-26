//
// Created by 宋峰 on 2021/4/1.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include "../medium/128LongestConsecutiveSequence.cpp"

using namespace std;

int main() {
    vector<int> vec({-6,6,-9,-7,0,3,4,-2,2,-1,9,-9,5,-3,6,1,5,-1,-2,9,-9,-4,-6,-5,6,-1,3});
//    vector<int> vec({100,4,200,1,3,2});
    for(auto v:vec){
        cout<<v<<" ";
    }
    cout<<endl;
    Solution sol;
    int n = sol.longestConsecutive(vec);
    sort(vec.begin(),vec.end());
    for(auto v:vec){
        cout<<v<<" ";
    }
    cout<<endl;
    cout << n << endl;
}