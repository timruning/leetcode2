//
// Created by 宋峰 on 2021/3/25.
//
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1, j = t.size() - 1;
        while (i >= 0 && j >= 0) {
            int num = 0;
            int num1 = 0;
            while (i >= 0) {
                if (s[i] == '#') {
                    num += 1;
                } else {
                    num1 += 1;
                }
                if (num1 > num) {
                    break;
                }
                i -= 1;
            }
            num = 0;
            num1 = 0;
            while (j >= 0) {
                if (t[j] == '#') {
                    num += 1;
                } else {
                    num1 += 1;
                }
                if (num1 > num) {
                    break;
                }
                j -= 1;
            }
            if (i >= 0 && j >= 0) {
                if (s[i] != t[j]) {
                    return false;
                }
                i -= 1;
                j -= 1;
            }
        }
        int num = 0;
        int num1 = 0;
        while (i >= 0) {
            if (s[i] == '#') {
                num += 1;
            } else {
                num1 += 1;
            }
            if (num1 > num) {
                break;
            }
            i -= 1;
        }
        num = 0;
        num1 = 0;
        while (j >= 0) {
            if (t[j] == '#') {
                num += 1;
            } else {
                num1 += 1;
            }
            if (num1 > num) {
                break;
            }
            j -= 1;
        }

        if (i < 0 && j < 0) {
            return true;
        } else {
            return false;
        }

    }
};