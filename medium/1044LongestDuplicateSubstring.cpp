//
// Created by 宋峰 on 2021/5/19.
//
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int compare(string s, int first, int second, int len) {
        if(first+len>s.size() || second+len>s.size()){
            return -1;
        }
        for(int i=len-1;i>=0;i--){
            if(s[first+i] != s[second+i]){
                return -1;
            }
        }
        while (first+len<s.size() || second+len<s.size()){
            if(s[first+len]==s[second+len]){
                len++;
            }else{
                break;
            }
        }
        return len;
    }

    string longestDupSubstring(string s) {
        int len = 0;
        int index = -1;
        unordered_map<char, vector<int>> mem;
        for (int i = 0; i < s.size(); i++) {
            if (mem.find(s[i]) != mem.end()) {
                mem[s[i]].push_back(i);
            } else {
                mem[s[i]] = vector<int>({i});
            }
            if (mem[s[i]].size() > 1) {
                len = 1;
                index = mem[s[i]][0];
            }
        }
        if(len==0){
            return "";
        }

        for (auto p:mem) {
            if (p.second.size() <= 1) {
                continue;
            }
            for (int i = 0; i < p.second.size(); i++) {
                for (int j = i + 1; j < p.second.size(); j++) {
                    int len2 = compare(s, i, j, len);
                    if (len2 > len) {
                        index = i;
                        len = len2;
                    }
                }
            }
        }

        return s.substr(index,len);
    }
};