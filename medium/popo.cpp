//
// Created by 宋峰 on 2021/5/17.
//

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int dp[100][100][100];

    int cal(vector<int> &boxes, int l, int r, int k) {
        if (l > r) {
            return 0;
        }
        if (dp[l][r][k] == 0) {
            int tmp = cal(boxes, l, r - 1, 0) + (k + 1) * (k + 1);
            for (int i = l; i < r; i++) {
                if (boxes[i] == boxes[r]) {
                    tmp = max(tmp, cal(boxes, l, i, k + 1) + cal(boxes, i + 1, r - 1, 0));
                }
            }
            dp[l][r][k] = tmp;
        }
        return dp[l][r][k];
    }

    int removeBoxes(vector<int> &boxes) {
        memset(dp, 0, sizeof dp);
        return cal(boxes, 0, boxes.size() - 1, 0);
    }
};