//
// Created by 宋峰 on 2021/5/25.
//
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include_next <iostream>

using namespace std;

class Solution {
public:
    int diff(string a, string b) {
        int result = 0;
        if (a.size() != b.size()) {
            return result;
        }
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                result++;
            }
        }
        return result;
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {
        unordered_map<string, unordered_set<string>> map;
        for (int i = 0; i < wordList.size(); i++) {
            if (diff(beginWord, wordList[i]) == 1) {
                if (map.find(beginWord) != map.end()) {
                    map[beginWord].insert(wordList[i]);
                } else {
                    map[beginWord] = unordered_set<string>({wordList[i]});
                }
            }
            for (int j = i + 1; j < wordList.size(); j++) {
                if (diff(wordList[i], wordList[j]) == 1) {
                    if (map.find(wordList[i]) != map.end()) {
                        map[wordList[i]].insert(wordList[j]);
                    } else {
                        map[wordList[i]] = unordered_set<string>({wordList[j]});
                    }

                    if (map.find(wordList[j]) != map.end()) {
                        map[wordList[j]].insert(wordList[i]);
                    } else {
                        map[wordList[j]] = unordered_set<string>({wordList[i]});
                    }
                }
            }
        }
        if (map.find(endWord) == map.end()) {
            return vector<vector<string>>();
        }
        vector<vector<string>> result_tmp({vector<string>({beginWord})});
        unordered_map<string,int> mem;
        mem[beginWord]=1;

        bool flag = true;
        while (flag) {
            int n = result_tmp.size();
            for (int i = 0; i < n; i++) {
                vector<string> list = result_tmp[i];
                string tail = result_tmp[i].back();
                if (map.find(tail) == map.end()) {
                    continue;
                }
                unordered_set<string> nebs = map[tail];
                for (auto word:nebs) {
                    if (word == endWord) {
                        flag = false;
                    }
                    if (mem.find(word) == mem.end() || mem[word] >  list.size()) {
                        vector<string> list_cp(list);
                        mem[word]=list_cp.size()+1;
                        list_cp.push_back(word);
                        result_tmp.push_back(list_cp);
                    }
                }
            }
            result_tmp.erase(result_tmp.begin(), result_tmp.begin() + n);

        }

        vector<vector<string>> result;
        for (auto v:result_tmp) {
            if (v.back() == endWord) {
                result.push_back(v);
            }
        }
        return result;
    }
};