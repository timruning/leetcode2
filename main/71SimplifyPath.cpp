//
// Created by 宋峰 on 2021/11/30.
//

#include "../medium/71SimplifyPath.cpp"
#include <iostream>

using namespace std;

int main() {
    string path = "/.../aa/gg/./cc/../d/.";
    Solution sol;
    string path2 = sol.simplifyPath(path);
    cout << path2 << endl;
}