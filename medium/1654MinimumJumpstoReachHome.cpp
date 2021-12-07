//
// Created by 宋峰 on 2021/12/2.
//
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    int minimumJumps(vector<int> &forbidden, int a, int b, int x) {
        set<int> forbidden1(forbidden.begin(), forbidden.end());
        if (0 == x) {
            return 0;
        }
        stack<int> sta;
        int pre = 0;
        while ((pre <= 4000 && pre >= -4000) || sta.size() > 0) {
            while ((pre <= 4000 && pre >= -4000) && forbidden1.count(pre) == 0) {
                sta.push(pre);
                forbidden1.insert(pre);
                pre += a;
                if (pre==x){
                    return sta.size();
                }
            }
            if (sta.size() > 0) {
                int top = sta.top();
                sta.pop();
                pre = top - b;
            }
        }
        return -1;
    }

    int minimumJumps1(vector<int> &forbidden, int a, int b, int x) {
        set<int> forbidden1(forbidden.begin(), forbidden.end());
        if (0 == x) {
            return 0;
        }
        queue<int> que;
        que.push(0);
        int jump = 1;
        while (que.size() > 0) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                int left = que.front() + a;
                if (left == x) {
                    return jump;
                } else if (left < 4000 && left > 0 && forbidden1.count(left) == 0) {
                    forbidden1.insert(left);
                    que.push(left);
                }
                int right = que.front() - b;
                if (right == x) {
                    return jump;
                } else if (right < 4000 && right > 0 && forbidden1.count(right) == 0) {
                    forbidden1.insert(right);
                    que.push(right);
                }
                que.pop();
            }
            for (int i = 0; i < que.size(); i++) {
                int t = que.front();
                que.pop();
                que.push(t);
                cout << t << " ";
            }
            cout << endl;
            jump += 1;
        }
        return -1;
    }
};