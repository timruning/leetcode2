//
// Created by 宋峰 on 2021/4/15.
//
#include <string>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:


    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        vector<TreeNode*> queue;
        queue.push_back(root);
        vector<int> mem;
        if(root== nullptr){
            return "";
        }else{
            mem.push_back(root->val);
        }
        while (queue.size()>0){
            TreeNode *head = queue.front();
            queue.erase(queue.begin());
            TreeNode *left = head->left;
            TreeNode *right = head->right;

            if(left!= nullptr){
                queue.push_back(left);
                mem.push_back(left->val);
            }else{
                mem.push_back(-10000);
            }
            if(right!= nullptr){
                queue.push_back(right);
                mem.push_back(right->val);
            }else{
                mem.push_back(-10000);
            }
        }
        string result = "";
        for(int i=0;i<mem.size()-1;i++){
            result = result.append(to_string(mem[i]));
            result = result.append(",");
        }
        result = result.append(to_string(mem[mem.size()-1]));
        cout<<result<<endl;
        return result;
    }

    int get_num(string data,int& i){
        bool flag = true;
        if(data[i]=='-'){
            flag= false;
            i++;
        }
        int result =0;
        while (i<data.size() && data[i]>='0' && data[i]<='9'){
            result= 10*result+data[i]-'0';
            i++;
        }
        if(flag){
            return result;
        }else{
            return -result;
        }
    }
    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        if(data.size()==0){
            return nullptr;
        }
        int i=0;
        int num = get_num(data,i);
        i++;
        TreeNode* root = new TreeNode(num);
        vector<TreeNode*> queue;
        queue.push_back(root);
        while (i<data.size()){

            TreeNode* head =queue.front();
            queue.erase(queue.begin());

            int left = get_num(data,i);

            if(left!= -10000){
                head->left = new TreeNode(left);
                queue.push_back(head->left);
            }
            i++;
            if(i>=data.size()){
                break;
            }
            int right = get_num(data,i);
            cout<<right<<endl;
            if(right!= -10000){
                head->right = new TreeNode(right);
                queue.push_back(head->right);
            }
            i++;
        }
        return root;
    }
};


// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));