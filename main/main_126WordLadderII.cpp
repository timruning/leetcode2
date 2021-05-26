//
// Created by 宋峰 on 2021/5/25.
//

#include <vector>
#include <iostream>
#include <string>
#include "../medium/126WordLadderII.cpp"
using namespace std;


/**
 * "red"
"tax"
["ted","tex","red","tax","tad","den","rex","pee"]
 * */

int main(){
    Solution sol;
    vector<string> wordList({"ted","tex","red","tax","tad","den","rex","pee"});
    vector<vector<string>> result = sol.findLadders("red","tax",wordList);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}