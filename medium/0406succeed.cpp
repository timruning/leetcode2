//
// Created by 宋峰 on 2020/5/7.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include "../import_iostream.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {

        if (p->right != NULL) {
            TreeNode *t = p->right;
            while (t->left != NULL) {
                t = t->left;
            }
            return t;
        }

        vector<TreeNode *> stack;
        while (root != NULL) {
            stack.push_back(root);
            if (p->val < root->val) {
                root = root->left;
            } else if (p->val > root->val) {
                root = root->right;
            } else {
                break;
            }
        }

        while (stack.size() > 1) {
            TreeNode *t = stack[stack.size() - 1];
            stack.pop_back();
            if (t == stack[stack.size() - 1]->left) {
                return stack[stack.size() - 1];
            }
        }
        return NULL;

    }
};

