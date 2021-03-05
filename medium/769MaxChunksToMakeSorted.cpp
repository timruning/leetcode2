//
// Created by 宋峰 on 2021/3/4.
//
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> arr_copy(arr);
        sort(arr_copy.begin(),arr_copy.end());
        unordered_map<int,int> map;
        for(int i=0;i<arr.size();i++){
            map[arr[i]]=i;
        }

        unordered_map<int,int> map2;
        for(int i=0;i<arr_copy.size();i++){
            map2[arr_copy[i]]=i;
        }


        int result=0;

        for(int i=0;i<arr_copy.size();i++){
            if(arr_copy[i]==arr[i]){
                result++;
            }else{
                int index = map[arr_copy[i]];
                for(;i<=index;i++){
                    if(arr[i]<=arr_copy[index]){
                        continue;
                    }else{
                        index=map2[arr[i]];
                    }
                }
                i--;
                result++;
            }
        }

        return result;
    }
};