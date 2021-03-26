//
// Created by 宋峰 on 2021/3/24.
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

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxPathSum(TreeNode *root) {
        vector<TreeNode *> stack;
        vector<int> left;
        vector<int> right;
        TreeNode *pre = root;
        int result = root->val;
        while (pre != nullptr || stack.size() > 0) {
            while (pre != nullptr) {
                stack.push_back(pre);
                left.push_back(0);
                right.push_back(0);
                if (pre->left != nullptr) {
                    pre = pre->left;
                } else {
                    pre = pre->right;
                }
            }
            result = stack[stack.size() - 1]->val > result ? stack[stack.size() - 1]->val : result;
            for (int i = stack.size() - 2; i >= 0; i--) {
                if (stack[i]->left == stack[i + 1]) {
                    int route = max(left[i + 1], right[i + 1]);
                    left[i] = stack[i + 1]->val + route > left[i] ? stack[i + 1]->val + route : left[i];
                    if (left[i] + right[i] + stack[i]->val > result) {
                        result = left[i] + right[i] + stack[i]->val;
                    }
                } else {
                    int route = max(left[i + 1], right[i + 1]);
                    right[i] = stack[i + 1]->val + route > right[i] ? stack[i + 1]->val + route : right[i];
                    if (left[i] + right[i] + stack[i]->val > result) {
                        result = left[i] + right[i] + stack[i]->val;
                    }

                }
            }

            TreeNode* tail=stack[stack.size()-1];
            stack.pop_back();
            left.pop_back();
            right.pop_back();

            while (stack.size()>0){
                TreeNode* tail2=stack[stack.size()-1];
                stack.pop_back();
                if(tail== tail2->left){
                    stack.push_back(tail2);
                    pre = tail2->right;
                    break;
                }else{
                    left.pop_back();
                    right.pop_back();
                    tail = tail2;
                }
            }

        }
        return result;
    }
};