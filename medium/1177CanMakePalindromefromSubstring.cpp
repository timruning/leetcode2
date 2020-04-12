//
// Created by timruning on 2020/4/12.
//
#include "../import_iostream.h"

class Solution {
public:
    int get_dif_num(string s){
        int begin =0 ;
        int end=s.size()-1;
        int n=0;
        while (begin<=end){
            if(s[begin]!=s[end]){
                n++;
            }
            begin++;
            end--;
        }
        return n;
    }
    bool check_paliquery(string s,int k){
        int num= get_dif_num(s);
        if(num<=k){
            return true;
        }else{
            return false;
        }
    }

    bool check_paliquery2(string s,int k){
        int abc[26]={0};
        for(char x:s){
            abc[x-'a']++;
        }
        int num;
        if(s.size()%2==0){
            num=0;
        }else{
            num = -1;
        }
        for(int i=0;i<26;i++){
            if(abc[i]%2==1){
                num+=1;
            }
        }
        if(num/2>k){
            return false;
        }else{
            return true;
        }
    }

    vector<vector<int>> get_vec(string s){
        vector<vector<int>> result(s.size());
        vector<int> freqChar(26);
        for(int i=0;i<s.size();i++){
            freqChar[s[i]-'a']++;
            result[i] = freqChar;
        }
        return result;
    }

    vector<bool> canMakePaliQueries2(string s, vector<vector<int>>& queries) {
        vector<vector<int>> freq= get_vec(s);
        vector<bool> result;
        for(vector<int> v: queries){
            vector<int> left(26,0);
            vector<int> right= freq[v[1]];
            if(v[0]>0){
                left= freq[v[0]-1];
            }
            int n = 0;
            if((v[1]-v[0]+1)%2==1){
                n= -1;
            }
            for(int i=0;i<26;i++){
                if((right[i]-left[i])%2==1){
                    n+=1;
                }
            }
            result.push_back(n/2 < v[2]);
        }
        return result;
    }

    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        //This is a tricky question
        int n=s.size();
        vector<int> freqChar(26);
        vector<vector<int>> v(n);  //v contains frequency of characaters till ith position for interval n
        for(int i=0;i<n;i++){
            freqChar[s[i]-'a']++;
            v[i]=freqChar;
        }
        int m=queries.size();
        vector<bool> ans(m);
        for(int i=0;i<m;i++){
            int l=queries[i][0],r=queries[i][1],k=queries[i][2];
            vector<int> charFreqInR(26);  //Tells character freq in given range
            for(int j=0;j<26;j++){
                if(l-1>=0){
                    charFreqInR[j]=v[r][j]-v[l-1][j];
                }
                else{
                    charFreqInR[j]=v[r][j];
                }
            }
            //Now I now which characters I have in the given range
            //Now I ahve to see if making palindrome is possible
            if((l==r)||((r-l+1)==(k-1))){
                ans[i]=true;
            }
            else{
                int changeNeeded=0;
                for(int k=0;k<26;k++){
                    changeNeeded+=charFreqInR[k]%2;
                }
                if(changeNeeded/2>k){
                    ans[i]=false;
                }
                else{
                    ans[i]=true;
                }
            }
        }
        return ans;
    }
};