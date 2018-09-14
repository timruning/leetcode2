//
// Created by 宋峰 on 2018/9/2.
//

#include <iostream>
#include <vector>
#include "../algorithm/775GlobalandLocalInversions.cpp"
using namespace std;

int main(){
    int a[]={1,0,2};
    vector<int> vec(a,a+3);
    Solution solution;
    bool result = solution.isIdealPermutation(vec);
    if(result)
        cout<<"hello"<<endl;
    else
        cout<<"bye"<<endl;
}