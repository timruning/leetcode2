//
// Created by timruning on 18-8-27.
//

#include <iostream>
#include "../medium/SubarraySumEqualsK.cpp"
using namespace std;

int main() {
    vector<int> num={1,1,1};
    int k=2;
    Solution solution;
    int t=solution.subarraySum(num,k);
    cout<<t<<endl;
}