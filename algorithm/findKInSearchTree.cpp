//
// Created by 宋峰 on 2018/9/20.
//
#include "../tree/tree.cpp"
#include <vector>
#include <iostream>
using namespace std;
int findKNodeInTree(TreeNode* root,int k){
    //zhongxu
    vector<TreeNode* > stack;
    int label=0;
    int num=0;
    stack.push_back(root);
    while (stack.size()>0){
        TreeNode *top=stack[stack.size()-1];
        if(label==0){
            if(top->left!= nullptr){
                stack.push_back(top->left);
            }else{
                TreeNode* right=top->right;
                stack.pop_back();
                cout<<top->val<<" ";
                num+=1;
                if(num==k){
                    return top->val;
                }
                if(right!= nullptr){
                    stack.push_back(right);
                    label=0;
                }else{
                    label=1;
                }
            }
        }else if(label==1){
            TreeNode* right=top->right;
            stack.pop_back();
            cout<<top->val<<" ";
            num+=1;
            if(num==k){
                return top->val;
            }
            if(right!= nullptr){
                stack.push_back(right);
                label=0;
            }else{
                label=1;
            }
        }
    }
    if(num<k){
        return -1;
    }
}
int findKNodeInTreeLeftFirst(TreeNode *root, int k) {
    //houxu search
    vector<TreeNode *> stack;
    int label = 0;
    int num = 0;
    stack.push_back(root);
    while (stack.size() > 0) {
        TreeNode *top = stack[stack.size() - 1];
        if (label == 0) {
            if (top->left != nullptr) {
                stack.push_back(top->left);
            }else if(top->right!= nullptr){
                stack.push_back(top->right);
            }else{
                stack.pop_back();
                cout<<top->val<<" ";
                num+=1;
                if(num==k){

                    return top->val;
                }
                if(stack.size()==0){
                    break;
                }
                TreeNode* top2=stack[stack.size()-1];
                if(top==top2->left){
                    label=1;
                }else{
                    label=2;
                }
            }
        }else if(label==1){
            if(top->right!= nullptr){
                stack.push_back(top->right);
                label=0;
            }else{
                stack.pop_back();
                cout<<top->val<<" ";
                num+=1;
                if(num==k){
                    return top->val;
                }
                if(stack.size()==0){
                    break;
                }
                TreeNode* top2=stack[stack.size()-1];
                if(top==top2->left){
                    label=1;
                }else{
                    label=2;
                }
            }
        }else if(label==2){
            stack.pop_back();
            cout<<top->val<<" ";
            num+=1;
            if(num==k){
                return top->val;
            }
            if(stack.size()==0){
                break;
            }
            TreeNode* top2=stack[stack.size()-1];
            if(top==top2->left){
                label=1;
            }else{
                label=2;
            }
        }
    }
    if(num<k){
        return -1;
    }
}