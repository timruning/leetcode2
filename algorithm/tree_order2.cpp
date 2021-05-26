//
// Created by 宋峰 on 2018/10/9.
//

#include <vector>
#include "../tree/tree.cpp"
#include <iostream>

using namespace std;

void pre_order1(TreeNode *root) {
    vector<TreeNode *> stack;
    TreeNode *pre = root;
    while (pre != nullptr || stack.size()>0) {
        while (pre!= nullptr){
            stack.push_back(pre);
            cout<< pre->val<<" ";
            pre= pre->left;
        }
        pre = stack[stack.size()-1];
        stack.pop_back();
        pre = pre->right;
    }
}

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

void mid_order1(TreeNode *root){
    TreeNode *pre = root;
    vector<TreeNode * > stack;
    while (pre!= nullptr || stack.size()>0){
        while (pre!= nullptr){
            stack.push_back(pre);
            pre=pre->left;
        }
        pre= stack[stack.size()-1];
        cout<<pre->val<<" ";
        stack.pop_back();
        pre=pre->right;
    }
}

void mid_order(TreeNode *root) {
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
            if (stack.size() == 0)
                break;
        }
    }
}
void post_order1(TreeNode *root) {
    TreeNode *pre =root;
    vector<TreeNode* > stack;
    while (pre!=nullptr){
        while (pre!= nullptr){
            stack.push_back(pre);
            if(pre->left!= nullptr){
                pre=pre->left;
            }else{
                pre=pre->right;
            }
        }
        TreeNode* tail1 = stack[stack.size()-1];
        cout<<tail1->val<<" ";
        stack.pop_back();
        while (stack.size()>0){
            TreeNode* tail2 = stack[stack.size()-1];
            stack.pop_back();
            if(tail1==tail2->left){
                stack.push_back(tail2);
                pre=tail2->right;
                break;
            }else{
                tail1=tail2;
                cout<<tail1->val<<" ";
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
        if ((cur->right == nullptr && cur->left == nullptr) ||
            (pre != nullptr && (pre == cur->left || pre == cur->right))) {
            pre = cur;
            cout << cur->val << " ";
            stack.pop_back();
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