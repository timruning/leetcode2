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
        if (height.size() <= 2) {
            return 0;
        }
        vector<int> max_left(height.size(), height.front());
        vector<int> max_right(height.size(), height.back());
        for (int i = 1; i < height.size(); i++) {
            max_left[i] = max(max_left[i - 1], height[i]);
        }

        for (int i = height.size() - 2; i >= 0; i--) {
            max_right[i] = max(max_right[i + 1], height[i]);
        }
        int result = 0;
        for (int i = 1; i < height.size() - 1; i++) {
            if (height[i] < max_left[i] && height[i] < max_right[i]) {
                result += (min(max_left[i], max_right[i]) - height[i]);
            }
        }
        return result;
    }

    int trap3(vector<int> &height) {
        if (height.size() <= 2) {
            return 0;
        }
        vector<int> max_right(height.size(), height.back());
        for (int i = height.size() - 2; i >= 0; i--) {
            max_right[i] = max(max_right[i + 1], height[i]);
        }
        vector<pair<int, int>> pools;
        int left = 0;
        int mi = left;
        for (int i = 1; i < height.size(); i++) {
            if (height[i] >= height[left] && i == left + 1) {
                left = i;
                mi = i;
                continue;
            }
            if (height[i] < height[mi]) {
                mi = i;
            } else {
                if (height[i] >= height[left] || height[i] == max_right[i]) {
                    pools.push_back(make_pair(left, i));
                    left = i;
                    mi = i;
                }
            }
        }
        int result = 0;
        int j = 0;
        for (int i = 0; i < height.size(); i++) {
            if (j >= pools.size()) {
                break;
            }
            int deep = min(height[pools[j].first], height[pools[j].second]);
            if (i >= pools[j].second) {
                j++;
            } else if (i > pools[j].first) {
                if (height[i] < deep) {
                    result += (deep - height[i]);
                }

            }
        }

        return result;
    }

    int trap2(vector<int> &height) {
        if (height.size() <= 2) {
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