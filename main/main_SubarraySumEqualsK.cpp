//
// Created by timruning on 18-8-27.
//

#include <iostream>
#include "../medium/SubarraySumEqualsK.cpp"
using namespace std;

int main() {
    vector<int> num={0,0,0};
    int k=0;
    Solution solution;
    int t=solution.subarraySum(num,k);
    cout<<t<<endl;
}