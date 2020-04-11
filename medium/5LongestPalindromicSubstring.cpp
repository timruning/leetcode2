//
// Created by 宋峰 on 2019/4/10.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int size= s.size();
        vector<bool> tmp(size, false);
        vector<vector<bool>> st(size,tmp);
        int max[]={0,0};
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                int a=j;
                int b=i+j;
                if(b<size){
                    if(a==b){
                        st[a][b]=true;
                    }else if(a+1==b && s[a]==s[b]){
                        st[a][b]=true;
                    }else if(a+1<size && b-1>=a && st[a+1][b-1]== true && s[a]==s[b]){
                        st[a][b]= true;
                    }
                    if(st[a][b]== true){
                        if(b-a>max[1]-max[0]){
                            max[0]=a;
                            max[1]=b;
                        }
                    }
                }
            }
        }

        return s.substr(max[0],max[1]-max[0]+1);
    }
};