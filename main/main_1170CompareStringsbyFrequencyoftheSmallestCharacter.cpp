//
// Created by 宋峰 on 2021/3/16.
//

#include <vector>
#include <iostream>
#include <string>
#include "../medium/1170CompareStringsbyFrequencyoftheSmallestCharacter.cpp"
using namespace std;

int main(){
    vector<string> queries({"bba","abaaaaaa","aaaaaa","bbabbabaab","aba","aa","baab","bbbbbb","aab","bbabbaabb"
    });
    vector<string> words({"aaabbb","aab","babbab","babbbb","b","bbbbbbbbab","a","bbbbbbbbbb","baaabbaab","aa"});

    Solution sol;
    vector<int> x = sol.numSmallerByFrequency(queries,words);
    for(int i=0;i<x.size();i++){
        cout<<x[i]<<" ";
    }
    cout<<endl;
}