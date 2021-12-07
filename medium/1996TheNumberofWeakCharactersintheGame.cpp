//
// Created by 宋峰 on 2021/12/7.
//
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;


class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        if(a[0]==b[0]){
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }

    int numberOfWeakCharacters1(vector<vector<int>>& props) {
        sort(props.begin(),props.end(),cmp);

        int mtn = INT_MIN;
        int answer = 0;

        for(int i = props.size()-1; i>=0; i--){
            if(mtn > props[i][1]){
                answer++;
            }else{
                mtn = max(mtn,props[i][1]);
            }
        }
        return answer;
    }

    int numberOfWeakCharacters(vector<vector<int>> &properties) {
        vector<int> mem(properties.size(), 0);
        sort(properties.begin(), properties.end(), cmp);
        int max = 0;

        int result = 0;
        for (int i = properties.size()-1; i>=0; i--) {
            if(max>properties[i][1]){
                result+=1;
            }else{
                max=properties[i][1];
            }
        }
        return result;
    }
};