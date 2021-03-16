//
// Created by 宋峰 on 2021/3/15.
//
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    int count(string s){
        unordered_map<char,int> map;
        int n=1;
        for(char c:s){
            if(map.find(c)==map.end()){
                map[c]=1;
            }else{
                map[c]+=1;
            }
            if(map[c]>n){
                n=map[c];
            }
        }
        return n;
    }

    int search(vector<int> words_n,int a,int begin,int end){
        if(words_n[begin]>=a){
            return begin-1;
        }
        if(words_n[end]<a){
            return end+1;
        }

        int midel = (begin+end)/2;
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
            if(index<0){
                result.push_back(words_n.size());
            }else if(index>=words_n.size()){
                result.push_back(0);
            }else{
                result.push_back(words_n.size()-index);
            }
        }

        return result;
    }
};