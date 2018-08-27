//
// Created by timruning on 18-8-27.
//
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numFriendRequests(vector<int> &ages) {
        if(ages.size()<=1){
            return 0;
        }
        unordered_map<int,int> ageNum;
        for(int i=0;i<ages.size();i++){
            auto got=ageNum.find(ages[i]);
            if(got==ageNum.end()){
                ageNum.insert(pair<int,int>(ages[i],1));
            }else{
                int num=got->second+1;
                ageNum.erase(got);
                ageNum.insert(pair<int,int>(ages[i],num));
            }
        }
        vector<int> keys;
        for(auto iter:ageNum){
            keys.push_back(iter.first);
        }
        sort(keys.begin(),keys.end());
        int result=0;
        for(int i=0;i<keys.size();i++){
            if(keys[i]>14){
                auto got =ageNum.find(keys[i]);
                if(got->second>1){
                    result+=(got->second*(got->second)/2);
                }
            }
        }
        int num0=ageNum.find(keys[0])->second;
        for(int i=1;i<keys.size();i++){
            int numi=ageNum.find(keys[i])->second;
            result+=(num0*numi);
            num0=numi;
        }
        return result;
    }
};