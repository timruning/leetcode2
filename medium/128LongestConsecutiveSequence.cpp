//
// Created by 宋峰 on 2021/4/1.
//
#include <vector>

#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        if (nums.size() == 0) {
            return 0;
        }
        unordered_map<int, pair<int, int>> map;
        for (int i = 0; i < nums.size(); i++) {
            int left =nums[i];
            int right =nums[i];
            while (true){
                int tmp_left =left;
                int tmp_right = right;
                if(map.find(left)!=map.end()){
                    pair<int,int> tmp = map[left];
                    tmp_left = min(tmp_left,tmp.first);
                    tmp_right = max(tmp_right,tmp.second);
                }
                if(map.find(right)!=map.end()){
                    pair<int,int> tmp = map[right];
                    tmp_left = min(tmp_left,tmp.first);
                    tmp_right = max(tmp_right,tmp.second);
                }
                if(map.find(left - 1)!=map.end()){
                    pair<int,int> tmp = map[left-1];
                    tmp_left = min(tmp_left,tmp.first);
                    tmp_right = max(tmp_right,tmp.second);
                }

                if(map.find(right+1)!=map.end()){
                    pair<int,int> tmp = map[right+1];
                    tmp_left = min(tmp_left,tmp.first);
                    tmp_right = max(tmp_right,tmp.second);
                }
                if(tmp_left==left && tmp_right==right){
                    left = tmp_left;
                    right=tmp_right;
                    break;
                }else{
                    left = tmp_left;
                    right=tmp_right;
                }
            }

            map[left]= pair<int,int>(left,right);
            map[right]= pair<int,int>(left,right);
        }
        int result =1;
        for(auto v:map){
            if(v.second.second-v.second.first+1>result){
                result= v.second.second-v.second.first+1;
            }
        }
        return result;
    }
};