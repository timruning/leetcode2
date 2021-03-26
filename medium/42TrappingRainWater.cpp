//
// Created by 宋峰 on 2021/3/25.
//
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

class Solution {
public:

    int trap(vector<int> &height) {
        if(height.size()<=2){
            return 0;
        }
        vector<int> sums(height.size(), height[0]);
        vector<pair<int, int> > height2(height.size(), pair<int, int>(0, height[0]));
        for (int i = 1; i < height.size(); i++) {
            sums[i] = sums[i - 1] + height[i];
            height2[i] = pair<int, int>(i, height[i]);
        }
        sort(height2.begin(), height2.end(), compare);

        int result = 0;
        int right = 0;
        int left = 0;
        if (height2[0].first > height2[1].first) {
            left = height2[1].first;
            right = height2[0].first;
            result = height2[1].second * (right - left) - sums[right] + sums[left] + height[right] -
                    height[left];
        } else {
            left = height2[0].first;
            right = height2[1].first;
            result = height2[1].second * (right - left) - sums[right] + sums[left];
        }


        for (int i = 2; i < height2.size(); i++) {
            if (height2[i].first >= left && height2[i].first <= right) {
                continue;
            } else if (height2[i].first < left) {
                result = result + height2[i].second * (left - height2[i].first) - sums[left] + sums[height2[i].first] +
                        height[left] - height2[i].second;
                left = height2[i].first;
            } else {
                result = result + height2[i].second * (height2[i].first - right) - sums[height2[i].first] + sums[right];
                right = height2[i].first;
            }
        }

        return result;
    }
};