//
// Created by 宋峰 on 2021/3/15.
//
#include <vector>
#include <iostream>
//#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    int count(string s){
        int n=1;
        char c=s[0];
        for(int i=1;i<s.size();i++){
            if(s[i]==c){
                n+=1;
            }else if(s[i]<c){
                c=s[i];
                n=1;
            }
        }
        return n;
    }

    int search(vector<int> words_n,int a,int begin,int end){
        if(words_n[begin]>a){
            return begin;
        }
        if(words_n[end]<=a){
            return end+1;
        }

        int midel = (begin+end)/2;
        if(midel == begin){
            return end;
        }
        if(words_n[midel]>a && words_n[midel-1]<=a){
            return midel;
        }else if(words_n[midel]>a && words_n[midel-1]>a){
            return search(words_n,a,begin,midel);
        }else{
            return search(words_n,a,midel,end);
        }

    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> query_n(queries.size(),1);
        vector<int> words_n(words.size(),1);
        for(int i=0;i<queries.size();i++){
            query_n[i]=count(queries[i]);
        }

        for(int i=0;i<words.size();i++){
            words_n[i]=count(words[i]);
        }
        sort(words_n.begin(),words_n.end());

        vector<int> result;

        for(int i=0;i<queries.size();i++){
            int index = search(words_n,query_n[i],0,words_n.size()-1);
            result.push_back(words_n.size()-index);
        }

        return result;
    }
};