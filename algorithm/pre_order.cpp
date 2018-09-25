//
// Created by 宋峰 on 2018/9/21.
//

#include <iostream>
#include "../tree/tree.cpp"

using namespace std;

void postOrder2(TreeNode *root) {
    vector<TreeNode *> stack;
    TreeNode *cur = root;
    TreeNode *pre = nullptr;
    stack.push_back(root);
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

void postOrder(TreeNode *root) {
    vector<TreeNode *> stack1;
    vector<TreeNode *> stack2;
    TreeNode *p = root;
    stack1.push_back(root);
    while (stack1.size() > 0) {
        TreeNode *top = stack1[stack1.size() - 1];
        stack1.pop_back();
        stack2.push_back(top);
        if (top->left != nullptr) {
            stack1.push_back(top->left);
        }
        if (top->right != nullptr) {
            stack1.push_back(top->right);
        }
    }
    while (stack2.size() > 0) {
        TreeNode *top = stack2[stack2.size() - 1];
        cout << top->val << " ";
        stack2.pop_back();
    }
}

void middleOrder(TreeNode *root) {
    vector<TreeNode *> stack;
    TreeNode *p = root;
    while (p != nullptr) {
        while (p != nullptr) {
            stack.push_back(p);
            p = p->left;
        }
        while (p == nullptr) {
            TreeNode *top = stack[stack.size() - 1];
            cout << top->val << " ";
            p = top->right;
            stack.pop_back();
            if (stack.size() == 0) {
                break;
            }
        }
    }
}

void preOrder(TreeNode *root) {
    vector<TreeNode *> stack;
    TreeNode *p = root;
    while (p != nullptr) {
        while (p != nullptr) {
            cout << p->val << " ";
            stack.push_back(p);
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