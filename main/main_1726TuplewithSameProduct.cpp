//
// Created by 宋峰 on 2021/3/5.
//

#include <vector>
#include <iostream>
#include "../medium/1726TuplewithSameProduct.cpp"
int main(){
    vector<int> vec({2,3,4,6,8,12});
    Solution sol;
    int n=sol.tupleSameProduct(vec);
    cout<<n<<endl;
}