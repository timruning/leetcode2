//
// Created by 宋峰 on 2021/3/5.
//
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int tupleSameProduct(vector<int> &nums) {
        int result = 0;
        unordered_map<int,vector<pair<int,int>>> map;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]==nums[j]){
                    continue;
                }
                int mi = nums[i]<nums[j]?nums[i]:nums[j];
                int ma = nums[i]>nums[j]?nums[i]:nums[j];
                int x = nums[i]*nums[j];
                if(map.find(x)!=map.end()){
                    vector<pair<int,int>> info = map.find(x)->second;

                    bool find=true;
                    int result2 =0;
                    for(auto v :info){
                        if(mi == v.first && ma== v.second){
                            find= false;
                            break;
                        }
                        if(mi!=v.first && mi!=v.second && ma!=v.first && ma!=v.second){
                            result2+=8;
                        }
                    }
                    if(find){
                        result+=result2;
                        info.push_back(pair<int,int>(mi,ma));
                        map[x]=info;
                    }
                }else{
                    vector<pair<int,int>> info({pair<int,int>(mi,ma)});
                    map[x]=info;
                }
            }
        }
        return result;
    }
};