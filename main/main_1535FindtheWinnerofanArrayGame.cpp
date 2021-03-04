//
// Created by 宋峰 on 2021/3/3.
//

#include <vector>
#include <iostream>
#include "../medium/1535FindtheWinnerofanArrayGame.cpp"

int main(){
    Solution sol;
    vector<int> vec({2,1,3,5,4,6,7});
    int t = sol.getWinner(vec,2);
    cout<<t<<endl;
}