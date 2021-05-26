//
// Created by 宋峰 on 2021/4/6.
//
#include <vector>

using namespace std;

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>> &points, int k) {
        int result = 0;
        bool flag = true;
        int max = 1;
        int left = 1;
        for (int i = 0; i < points.size(); i++) {
            bool false_max = false;
            if(max<=i || points[max][0]-points[i][0]>k){
                false_max= true;
            }else{
                if(points[max][0]-points[i][0] + points[max][1]+points[i][1]>result || flag){
                    result= points[max][0]-points[i][0] + points[max][1]+points[i][1];
                    flag=false;
                }
            }
            for(int j=left;j<points.size();j++){
                if(j<=i){
                    continue;
                }
                if(points[j][0]-points[i][0]>k){
                    break;
                }
                if(false_max== true || (false_max==false && points[j][1]+points[j][0]>=points[max][1]+points[max][0])){
                    max= j;
                    false_max= false;
                }
                if(points[j][0]-points[i][0] + points[j][1]+points[i][1]>result || flag){
                    result = points[j][0]-points[i][0] + points[j][1]+points[i][1];
                    flag=false;
                }
                left= j;
            }
        }
        return result;
    }
};