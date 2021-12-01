//
// Created by 宋峰 on 2021/6/2.
//

/**
 *  str="abca"
 *
 * */

#include <iostream>
#include <vector>
#include <string>

using namespace  std;

/**
 *  hdfabdfnadsfg
 *     i    j
 *
 * */
int get_diff_length(string s){

//    [0,0,0,0,0,0,0,0,0]

    vector<int> mem(26,0);
    if(s.size()==0){
        return 0;
    }
    int result =1;

    for(int i=0;i<s.size();){
        mem[s[i]-'a']+=1;
        int tmp =1;
        for(int j=i+1;j<s.size();j++){
            if(mem[s[j]-'a'] > 0){
                result = result> tmp ? result:tmp;
                while (s[i]!=s[j] && i<j){
                    mem[s[i]-'a']-=1;
                    i++;
                }
            }else{
                mem[s[j]-'a']++;
                tmp+=1;
            }
            if(j==s.size()-1){
                result = result> tmp ? result:tmp;
                break;
            }
        }
    }
    return result;
}

int main(){
//    string
}