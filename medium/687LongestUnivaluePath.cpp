//
// Created by 宋峰 on 2021/2/26.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <vector>
#include <iostream>
#include <stdio.h>
#include <unordered_map>

int null = (int) (0x80000001);
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *buildTree(int a[], int n) {
    vector<TreeNode *> queue;
    TreeNode *root = nullptr;
    if (n == 0) {
        return root;
    }
    root = new TreeNode(a[0]);
    queue.push_back(root);
    int index = 1;
    while (queue.size() > 0) {
        TreeNode *father = queue[0];
        if (father == NULL) {
            index += 2;
            queue.push_back(NULL);
            queue.push_back(NULL);
            queue.erase(queue.begin());
            continue;
        }
        int left = index;
        int right = index + 1;
        index += 2;
        TreeNode *left_node = NULL;
        TreeNode *right_node = NULL;
        if (left < n) {
            if (a[left] != null) {
                left_node = new TreeNode(a[left]);
            }
            queue.push_back(left_node);
        } else {
            break;
        }
        if (right < n) {
            if (a[right] != null) {
                right_node = new TreeNode(a[right]);
            }
            queue.push_back(right_node);
        } else {
            break;
        }
        father->left = left_node;
        father->right = right_node;
        queue.erase(queue.begin());
    }
    return root;
}

class Solution {
public:
    int longestUnivaluePath(TreeNode *root) {
        TreeNode *pre = root;
        vector<TreeNode *> stack;
        unordered_map<TreeNode *, pair<int, int>> map;
        while (pre != NULL || stack.size() > 0) {
            while (pre != NULL) {
                stack.push_back(pre);
                if (pre->left != NULL) {
                    pre = pre->left;
                } else {
                    pre = pre->right;
                }
            }
            vector<int> left(stack.size(), 0);
            for (int i = stack.size() - 2; i >= 0; i--) {
                if (stack[i]->val == stack[i + 1]->val) {
                    if (stack[i]->left == stack[i + 1]) {
                        left[i] = left[i + 1] + 1;
                        if (map.find(stack[i]) != map.end()) {
                            map[stack[i]].first = map[stack[i]].first > left[i] ? map[stack[i]].first : left[i];
                        }else{
                            map[stack[i]] = pair<int,int>(left[i],0);
                        }
                    } else {
                        left[i] = left[i + 1] + 1;
                        if (map.find(stack[i]) != map.end()) {
                            map[stack[i]].second = map[stack[i]].second > left[i] ? map[stack[i]].second : left[i];
                        }else{
                            map[stack[i]] = pair<int,int>(0,left[i]);
                        }
                    }
                }
            }
            TreeNode *tail1 = stack[stack.size() - 1];
            stack.pop_back();
            while (stack.size() > 0) {
                TreeNode *tail2 = stack[stack.size() - 1];
                stack.pop_back();
                if (tail1 == tail2->left) {
                    stack.push_back(tail2);
                    pre = tail2->right;
                    break;
                } else {
                    tail1 = tail2;
                }
            }

        }
        int result=0;
        for(auto v:map){
            if(v.second.first+v.second.second > result){
                result = v.second.first+v.second.second;
            }
        }
        return result;
    }
};