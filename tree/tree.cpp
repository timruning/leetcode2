//
// Created by timruning on 18-8-27.
//

#include<vector>
#include <stdio.h>

using namespace std;
int null = (int) (0x80000001);

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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