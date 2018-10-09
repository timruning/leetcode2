//
// Created by 宋峰 on 2018/9/25.
//

#include <vector>
#include <iostream>
#include "../easy/11ContainerWithMostWater.cpp"

using namespace std;
int main(){
    Solution solution;
    int a[]={1,1};
    vector<int> vec(a,a+ sizeof(a)/ sizeof(int));
    int result=solution.maxArea(vec);
    cout<<result<<endl;
}