//
//  1711CountGoodMeals.cpp
//  leet_code_xcode
//
//  Created by 宋峰 on 2021/2/19.
//

#include <stdio.h>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        vector<int> set;
        int begin=1;
        int tmp = 1e9+7;
        for(int i=0;i<25;i++){
            set.push_back(begin);
            begin*=2;
        }
    
        int count=0;
        if(deliciousness.size()<=1){
            return count;
        }
        
        unordered_map<int, int> id_count;
        id_count.insert(make_pair(deliciousness[0], 1));
        for(int i=1;i<deliciousness.size();i++){
            for(int x:set){
                if(x<deliciousness[i])
                    continue;
                int d = x- deliciousness[i];
                unordered_map<int, int>::iterator num = id_count.find(d);
                if(num!=id_count.end()){
                    count+=num->second;
                    count = count%tmp;
                }
            }
            
            unordered_map<int, int>::iterator num2 = id_count.find(deliciousness[i]);
            if(num2!=id_count.end()){
                id_count[deliciousness[i]] =num2->second+1;
//                id_count.insert(make_pair(deliciousness[i], num2->second+1));
            }else{
                id_count.insert(make_pair(deliciousness[i], 1));
            }
        }
        return count;
    }
};
