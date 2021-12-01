//
// Created by 宋峰 on 2021/11/30.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string result;
        vector<int> index(1, 0);
        for (int i = 0; i < path.size(); i++) {
            string s = "";
            while (path[i] != '/' && i < path.size()) {
                s += path[i];
                i++;
            }
            if (s=="." || s=="") {
                continue;
            } else if (s=="..") {
                if(index.size()>1){
                    result = result.substr(0, index.back());
                    index.pop_back();
                }else{
                    result="";
                }
            } else {
                index.push_back(result.size());
                result = result + "/" + s;
            }
        }
        if(result==""){
            result="/";
        }
        return result;
    }
};