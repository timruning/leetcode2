//
// Created by 宋峰 on 2021/3/3.
//
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string make_key(int a, int b) {
        return to_string(a) + "_" + to_string(b);
    }

    int unhappyFriends(int n, vector<vector<int>> &preferences, vector<vector<int>> &pairs) {
        vector<int> unhappys(n, 0);
        unordered_set<string> pairs_s;
        for (int i = 0; i < pairs.size(); i++) {
            pairs_s.insert(make_key(pairs[i][0], pairs[i][1]));
            pairs_s.insert(make_key(pairs[i][1], pairs[i][0]));
        }
        for (int i = 0; i < pairs.size(); i++) {
            int x = pairs[i][0];
            int y = pairs[i][1];
            if(unhappys[x]==0){
                for (int j = 0; j < preferences[x].size() && preferences[x][j] != y; j++) {
                    int u = preferences[x][j];
                    for (int q = preferences[u].size() - 1; q >= 0 && preferences[u][q] != x; q--) {
                        int v = preferences[u][q];
                        if (pairs_s.find(make_key(u, v)) != pairs_s.end()) {
                            unhappys[x]=1;
                            unhappys[u]=1;
                        }
                    }
                }
            }
            if(unhappys[y]==0){
                for (int j = 0; j < preferences[y].size() && preferences[y][j] != x; j++) {
                    int u = preferences[y][j];
                    for (int q = preferences[u].size() - 1; q >= 0 && preferences[u][q] != y; q--) {
                        int v = preferences[u][q];
                        if (pairs_s.find(make_key(u, v)) != pairs_s.end()) {
                            unhappys[y]=1;
                            unhappys[u]=1;
                        }
                    }
                }
            }
        }
        int result = 0;
        for(auto v:unhappys){
            result+=v;
        }
        return result;
    }
};