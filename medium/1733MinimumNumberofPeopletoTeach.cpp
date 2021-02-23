//
// Created by 宋峰 on 2021/2/22.
// 1733MinimumNumberofPeopletoTeach.cpp
//



#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    unordered_set<int> conbine(unordered_set<int> a, unordered_set<int> b) {

        unordered_set<int> total;
        for (auto x: a) {
            if (b.find(x) != b.end()) {
                total.insert(x);
            }
        }

        return total;
    }

    int minimumTeachings(int n, vector<vector<int>> &languages, vector<vector<int>> &friendships) {

        vector<int> learn(n, 0);
        vector<unordered_set<int>> languages2;
        for (int i = 0; i < languages.size(); i++) {
            unordered_set<int> lan;
            for (int j = 0; j < languages[i].size(); j++) {
                lan.insert(languages[i][j]);
            }
            languages2.push_back(lan);
        }
        unordered_set<int> users;
        int t=0;
        for (int i = 0; i < friendships.size(); i++) {
            int a = friendships[i][0];
            int b = friendships[i][1];
            unordered_set<int> lan_a = languages2[a - 1];
            unordered_set<int> lan_b = languages2[b - 1];

            unordered_set<int> diff = conbine(lan_a, lan_b);
            if (diff.size() > 0) {
                continue;
            }

            if (users.find(a) == users.end()) {
                for (auto v:lan_a) {
                    learn[v - 1] += 1;
                }
                users.insert(a);
                t+=1;
            }

            if (users.find(b) == users.end()) {
                for (auto v:lan_b) {
                    learn[v - 1] += 1;
                }
                users.insert(b);
                t+=1;
            }

        }

        int result = languages.size();
        for (int i = 0; i < learn.size(); i++) {
            if (t - learn[i] < result) {
                result = t - learn[i];
            }
        }
        return result;
    }
};