//
// Created by 宋峰 on 2021/3/8.
//

#include <vector>
#include <iostream>
#include "../medium/1481LeastNumberofUniqueIntegersafterKRemovals.cpp"
using namespace std;
int main(){
    vector<int> vec({5,5,4});
    Solution sol;
    int n = sol.findLeastNumOfUniqueInts(vec,1);
    cout<<n<<endl;
}