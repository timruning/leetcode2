//
// Created by 宋峰 on 2019/4/11.
//

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {

        while (prerequisites.size()>0){
            vector<pair<int,int>> sta(numCourses,pair<int,int>(0,0));
            for(auto v:prerequisites){
                sta[v.first].first+=1;
                sta[v.second].second+=1;
            }
            bool find=false;
            for(int i=0;i<sta.size();i++){
                if(sta[i].first>0 && sta[i].second==0){
                    find=true;
                    for(auto iter=prerequisites.begin();iter!=prerequisites.end();){
                        if(iter->first==i){
                             iter = prerequisites.erase(iter);
                        }else{
                            iter+=1;
                        }
                    }
                    sta[i].first = -1;
                }
            }
            if(find==false){
                break;
            }
        }
        if(prerequisites.size()>0){
            return false;
        }else{
            return true;
        }
    }
};