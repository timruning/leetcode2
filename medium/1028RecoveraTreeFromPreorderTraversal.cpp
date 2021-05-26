//
// Created by 宋峰 on 2021/4/14.
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
#include <string>
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
    int get_num(string s,int& i){
        int result=0;
        while (i<s.size() && s[i]>='0' && s[i]<='9'){
            result= result*10 + s[i]-'0';
            i++;
        }
        return result;
    }

    int get_dash(string s,int& i){
        int result=0;
        while (i<s.size() && s[i]=='-' ){
            result+=1;
            i++;
        }
        return result;
    }
    TreeNode* recoverFromPreorder(string S) {
        int i=0;
        int root_num = get_num(S,i);
        TreeNode *root = new TreeNode(root_num);
        vector<TreeNode*> stack;
        stack.push_back(root);
        while (i<S.size()){
            int dash_num= get_dash(S,i);
            if(dash_num == 0 || i>= S.size()){
                break;
            }
            int num = get_num(S,i);
            TreeNode* tmp_node =new TreeNode(num);
            while (stack.size()>dash_num){
                stack.pop_back();
            }
            if(stack[stack.size()-1]->left!= nullptr){
                stack[stack.size()-1]->right=tmp_node;
            }else{
                stack[stack.size()-1]->left=tmp_node;
            }
            stack.push_back(tmp_node);
        }
        return root;
    }
};