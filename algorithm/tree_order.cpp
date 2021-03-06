//
// Created by 宋峰 on 2018/9/25.
//

#include <vector>
#include <iostream>
#include "../tree/tree.cpp"

using namespace std;

void pre_order(TreeNode *root) {
    vector<TreeNode *> stack;
    TreeNode *p = root;
    while (p != nullptr) {
        while (p != nullptr) {
            stack.push_back(p);
            cout << p->val << " ";
            p = p->left;
        }
        while (p == nullptr) {
            TreeNode *top = stack[stack.size() - 1];
            stack.pop_back();
            p = top->right;
            if (stack.size() == 0)
                break;
        }
    }
}

void middle_order(TreeNode *root) {
    vector<TreeNode *> stack;
    TreeNode *p = root;
    while (p != nullptr) {
        while (p != nullptr) {
            stack.push_back(p);
            p = p->left;
        }
        while (p == nullptr) {
            TreeNode *top = stack[stack.size() - 1];
            stack.pop_back();
            cout << top->val << " ";
            p = top->right;
            if (stack.size() == 0) {
                break;
            }
        }
    }
}

void post_order(TreeNode *root) {
    vector<TreeNode *> stack;
    TreeNode *cur = root;
    TreeNode *pre = nullptr;
    stack.push_back(cur);
    while (stack.size() > 0) {
        cur = stack[stack.size() - 1];
        if ((cur->left == nullptr && cur->right == nullptr) ||
            (pre != nullptr && (pre == cur->left || pre == cur->right))) {
            cout << cur->val << " ";
            stack.pop_back();
            pre = cur;
        } else {
            if (cur->right != nullptr) {
                stack.push_back(cur->right);
            }
            if (cur->left != nullptr) {
                stack.push_back(cur->left);
            }
        }
    }
}