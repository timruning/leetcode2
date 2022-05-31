//
// Created by 宋峰 on 2021/6/2.
//

#include <iostream>
#include <vector>
#include <string>
#include "../medium/844BackspaceStringCompare.cpp"

using namespace std;


int main() {
//    string s = "bxj##tw";
//    string t = "bxo#j##tw";

//    string s = "ab##";
//    string t = "a#b#";
    string s = "nzp#o#g";
    string t = "b#nzp#o#g";
    Solution solution;
    cout << solution.backspaceCompare(s, t) << endl;
}