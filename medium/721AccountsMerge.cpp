//
// Created by timruning on 2020/5/3.
//

#include "../import_iostream.h"
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int getIndex(vector<int> &index, int x) {
        vector<int> tmp;
        while (index[x] != x && x != 0) {
            tmp.push_back(x);
            x = index[x];
        }
        for (auto v: tmp) {
            index[v] = x;
        }
        return x;
    }

    int setIndex(vector<int> &index, int x, int min) {
        vector<int> tmp;
        while (index[x] != x && x > min) {
            int tmp = index[x];
            index[x] = min;
            x = tmp;
        }
        if (x != 0)
            index[x] = min;
        return x;
    }

    vector<vector<string>> accountsMerge1(vector<vector<string>> &accounts) {
        vector<int> index(accounts.size(), 0);
        for (int i = 0; i < accounts.size(); i++) {
            index[i] = i;
        }
        unordered_map<string, int> email2uid;
        for (int i = 0; i < accounts.size(); i++) {
            int min = i;
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];
                if (email2uid.find(email) != email2uid.end()) {
                    int tmp = getIndex(index, email2uid[email]);
                    if (tmp < min) {
                        min = tmp;
                    }
                }
            }
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];
                index[i] = min;
                setIndex(index, email2uid[email], min);
                email2uid[email] = min;
            }
            index[i] = min;
        }
        unordered_map<int, unordered_set<string>> resultTmp;
        for (int i = 0; i < index.size(); i++) {
            int uid = getIndex(index, i);
            unordered_set<string> tmp;
            if (resultTmp.find(uid) != resultTmp.end()) {
                tmp = resultTmp[uid];
            }
            tmp.insert(accounts[i].begin() + 1, accounts[i].end());
            resultTmp[uid] = tmp;
        }
        vector<vector<string>> result;
        for (auto v:resultTmp) {
            string acc = accounts[v.first][0];
            vector<string> ems;
            ems.insert(ems.begin(), v.second.begin(), v.second.end());
            sort(ems.begin(), ems.end());
            ems.insert(ems.begin(), acc);
            result.push_back(ems);
        }
        return result;
    }

    unordered_map<string, vector<string>> graph;
    unordered_set<string> meets;

    void dfs(string begin,vector<string>& list){
        meets.insert(begin);
        list.push_back(begin);
        vector<string> neier =graph[begin];
        for(auto v: neier){
            if(meets.find(v)== meets.end()){
                dfs(v,list);
            }
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {

        for (auto acc : accounts) {
            for (int i = 2; i < acc.size(); i++) {
                graph[acc[i]].push_back(acc[i - 1]);
                graph[acc[i - 1]].push_back(acc[i]);
            }
        }
        vector<vector<string>> result;
        for (auto acc:accounts) {
            if(meets.find(acc[1]) == meets.end()){
                vector<string> tmp;
                tmp.push_back(acc.front());
                dfs(acc[1],tmp);
                sort(tmp.begin() + 1, tmp.end());
                result.push_back(tmp);
            }
        }
        return result;
    }
};