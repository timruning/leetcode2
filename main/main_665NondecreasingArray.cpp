//
//  main_665NondecreasingArray.cpp
//  leet_code_xcode
//
//  Created by 宋峰 on 2021/2/18.
//

#include <iostream>
#include "../algorithm/665NondecreasingArray.cpp"

int main(){
    vector<int> a({4,2,3});
    Solution sol;
    if(sol.checkPossibility(a)){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
}
