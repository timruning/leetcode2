//
// Created by 宋峰 on 2021/3/2.
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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d==1){
            TreeNode* newNode = new TreeNode(v);
            newNode->left=root;
            return newNode;
        }
        vector<TreeNode* > stack;
        TreeNode* pre=root;
        while (pre!=NULL || stack.size()>0){
            while (pre!=NULL){
                stack.push_back(pre);
                if(stack.size()==d-1){
                    TreeNode* newNode1 = new TreeNode(v);
                    TreeNode* newNode2 = new TreeNode(v);
                    newNode1->left=pre->left;
                    pre->left=newNode1;
                    newNode2->right=pre->right;
                    pre->right=newNode2;
                }
                if(pre->left!=NULL){
                    pre=pre->left;
                }else{
                    pre=pre->right;
                }
            }

            TreeNode* tail = stack[stack.size()-1];
            stack.pop_back();
            while (stack.size()>0){
                TreeNode* tail2 = stack[stack.size()-1];
                stack.pop_back();
                if(tail==tail2->left){
                    stack.push_back(tail2);
                    pre=tail2->right;
                    break;
                }else{
                    tail=tail2;
                }
            }
        }
        return root;
    }
};