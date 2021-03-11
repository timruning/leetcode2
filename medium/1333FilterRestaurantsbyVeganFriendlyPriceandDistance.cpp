//
// Created by 宋峰 on 2021/3/10.
//
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<int> result;
        for(int i=0;i<restaurants.size();i++){
            vector<int> item = restaurants[i];
            if(((veganFriendly && item[2]==1)|| veganFriendly == false ) && item[3]<=maxPrice && item[4]<= maxDistance){
                bool flag = true;
                for(int j=0;j<result.size();j++){
                    if(item[1]>restaurants[result[j]][1] || (item[1]== restaurants[result[j]][1] && item[0] > restaurants[result[j]][0])){
                        result.insert(result.begin()+j,i);
                        flag=false;
                        break;
                    }
                }
                if(flag){
                    result.push_back(i);
                }
            }
        }
        vector<int> result2;
        for(int i=0;i<result.size();i++){
            result2.push_back(restaurants[result[i]][0]);
        }
        return result2;
    }
};