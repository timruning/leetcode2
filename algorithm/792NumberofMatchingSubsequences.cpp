//
// Created by 宋峰 on 2018/9/11.
//
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int binarySearch(vector<int> vec,int a,int b,int begin){
        cout<<"vec: ";
        for(int i=0;i<vec.size();i++){
            cout<<vec[i]<<" ";
        }
        cout<<"a:"<<a<<" b:"<<b<<" begin:"<<begin<<endl;
        int mid=(a+b)/2;
        if(a>=b || vec[b-1]<begin){
            return -1;
        }
        if(vec[mid]>=begin){
            if(mid==a || (mid>=1 && vec[mid-1]<begin)){
                return vec[mid];
            }else{
                return binarySearch(vec,a,mid,begin);
            }
        }else{
            return binarySearch(vec,mid+1,b,begin);
        }

    }
    bool check_word(unordered_map<char,vector<int> > charIndex,string word){
        int begin = 0;
        for(int i=0;i<word.size();i++){
            auto iter=charIndex.find(word[i]);
            if(iter!=charIndex.end()){
                cout<<"word: "<<word[i]<<endl;
                begin=binarySearch(iter->second,0,iter->second.size(),begin);
                cout<<"result: "<<begin<<endl;
                if(begin==-1){
                    return false;
                }
                begin+=1;
            }else{
                return false;
            }
        }
        return true;
    }
    int numMatchingSubseq(string S, vector<string>& words) {
        int size=words.size();
        if(size==0){
            return size;
        }
        unordered_map<char,vector<int> > charIndex;
        for(int i=0;i<S.size();i++){
            auto iter=charIndex.find(S[i]);
            if(iter!=charIndex.end()){
                iter->second.push_back(i);
            }else{
                vector<int> tmp;
                tmp.push_back(i);
                charIndex.insert(pair<char,vector<int> >(S[i],tmp));
            }
        }
        int result=0;
        for(int i=0;i<words.size();i++){
            if(check_word(charIndex,words[i])){
                result+=1;
            }
        }
        return result;
    }
};