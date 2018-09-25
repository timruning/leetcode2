//
// Created by 宋峰 on 2018/9/20.
//

#include <vector>
#include <iostream>
#include "../medium/287FindtheDuplicateNumber.cpp"

using namespace std;

int main() {
    Solution solution;
    int a[] = {1, 2, 4, 3, 2};
    vector<int> vec(a, a + 5);
    int find = solution.findDuplicate(vec);
    cout << find << endl;
}