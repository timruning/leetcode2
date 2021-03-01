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

class Solution {
public:
    int widthOfBinaryTree(TreeNode *root) {
        int result = 0;

        vector<pair<int , TreeNode *> > queue;
        vector<pair<int , TreeNode *> > queue2;
        if (root == NULL) {
            return result;
        }
        queue.push_back(pair<int , TreeNode *>(0, root));
        while (queue.size() > 0) {
            result = queue[queue.size() - 1].first - queue[0].first + 1 > result ? queue[queue.size() - 1].first -
                                                                                   queue[0].first + 1 : result;
            int miss=0;
            for(int i=0;i<queue.size();i++){
                TreeNode *pre = queue[i].second;
                int index = queue[i].first;

                if (pre->left != NULL) {
                    int index2 = 2 * index;
                    queue2.push_back(pair<int , TreeNode *>(index2, pre->left));
                }

                if (pre->right != NULL) {
                    int index2 = 2 * index + 1;
                    queue2.push_back(pair<int , TreeNode *>(index2, pre->right));
                }
            }

            queue.clear();
            queue = queue2;
            queue2.clear();
        }
        return result;
    }
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