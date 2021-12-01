//
// Created by 宋峰 on 2021/11/29.
//
#include <iostream>
#include "../medium/721AccountsMerge.cpp"

using namespace std;

int main() {
    Solution sol;
    vector<vector<string>> accouts = {{"John", "johnsmith@mail.com", "john_newyork@mail.com"},
                                      {"John", "johnsmith@mail.com", "john00@mail.com"},
                                      {"Mary", "mary@mail.com"},
                                      {"John", "johnnybravo@mail.com"}};
    vector<vector<string>> accouts1 = sol.accountsMerge(accouts);
    for (auto v:accouts1) {
        for (auto v1 : v) {
            cout << v1 << " ";
        }
        cout << endl;
    }
}