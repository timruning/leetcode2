//
// Created by 宋峰 on 2021/5/18.
//
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int old = 0;
        int tmp = 0;
        int result = 0;
        stack<char> sk;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                sk.push(s[i]);
            } else {
                if (sk.size() == 0) {
                    result= max(result,old);
                    old = 0;
                    tmp = 0;
                } else {
                    sk.pop();
                    tmp += 2;
                    if (sk.size() == 0) {
                        old = old + tmp;
                        tmp = 0;
                        result= max(result,old);
                    }
                }
            }
        }
        result= max(result,tmp);
        return result;
    }
};