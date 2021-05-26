//
// Created by 宋峰 on 2021/4/7.
//

#include <iostream>
#include <vector>
#include "../medium/1157OnlineMajorityElementInSubarray.cpp"

using namespace std;

int main() {
    vector<int> vec({1, 1, 2, 2, 1, 1});
    MajorityChecker *major = new MajorityChecker(vec);
    int a = major->query(0, 5, 4);
    cout << a << endl;

}