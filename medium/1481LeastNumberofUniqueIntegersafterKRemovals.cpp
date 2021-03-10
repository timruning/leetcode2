//
// Created by 宋峰 on 2021/3/8.
//
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool compare(pair<int,int> a,pair<int,int> b){
    return a.second < b.second;
}

class Solution {
public:

    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> map;
        for(int i=0;i<arr.size();i++){
            if(map.find(arr[i])!=map.end()){
                map[arr[i]]+=1;
            }else{
                map[arr[i]]=1;
            }
        }
        vector<pair<int,int>> vec;
        for(auto v:map){
            vec.push_back(v);
        }
        sort(vec.begin(),vec.end(), compare);
        int n=0;
        int sum=0;
        for(auto v:vec){
            if(v.second+sum<=k){
                n+=1;
                sum+=v.second;
            }else{
                break;
            }
        }
        return vec.size()-n;
    }
};