//
// Created by 宋峰 on 2019/4/7.
//

#include <iostream>
#include "../medium/907SumofSubarrayMinimums.cpp"
using namespace std;

int main(){
    int a[]={3,1,2,4};
    vector<int> b(a,a+4);
    cout<<b.back()<<endl;
    Solution solution;
    int t=solution.sumSubarrayMins2(b);
    cout<<t<<endl;
}