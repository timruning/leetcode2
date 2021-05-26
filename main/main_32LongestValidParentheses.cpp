//
// Created by 宋峰 on 2021/5/18.
//

#include "../medium/32LongestValidParentheses.cpp"
#include <string>
#include <iostream>
using namespace std;
int main(){
    string x= "(((()(()";
    Solution sol;
    int n = sol.longestValidParentheses(x);
    cout<<n<<endl;
}