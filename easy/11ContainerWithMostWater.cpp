//
// Created by 宋峰 on 2018/9/25.
//
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int begin = 0;
        int end = height.size() - 1;
        int h1 = height[begin];
        int h2 = height[end];
        int area=0;
        int h;
        for (int i = 0; i < height.size(); i++) {
            int l=end-begin;
            if (h1 > h2) {
                h=h2;
                end-=1;
                if(end<begin)
                    break;
                h2=height[end];
            }else{
                h=h1;
                begin+=1;
                if(begin>end)
                    break;
                h1=height[begin];
            }
            int tmp=h*l;
            area=tmp>area?tmp:area;
        }
        return area;
    }
};