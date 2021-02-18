//
// Created by 宋峰 on 2018/9/1.
//

#include <iostream>
#include "../algorithm/93RestoreIPAddresses.cpp"

using namespace std;

int main() {
    string s="240102";
    Solution sol ;
    vector<string> result = sol.restoreIpAddresses(s);
    for(auto v:result){
        cout<<v<<endl;
    }
}