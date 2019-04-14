//
// Created by 宋峰 on 2019/4/10.
//

#include <iostream>
#include "../medium/5LongestPalindromicSubstring.cpp"
using namespace std;

int main(){
    Solution solution;
    string aa="sjdfjg";
    cout<<aa.substr(0,4)<<endl;
    string a = solution.longestPalindrome("abbc");
    cout<<a<<endl;
}