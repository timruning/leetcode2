//
//  main_1711CountGoodMeals.cpp
//  leet_code_xcode
//
//  Created by 宋峰 on 2021/2/19.
//

#include <stdio.h>
#include <vector>
#include "../algorithm/1711CountGoodMeals.cpp"
using namespace std;
int main(){
    vector<int> vec({64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64,64});
    Solution sol;
    cout<< sol.countPairs(vec) << endl;
}
