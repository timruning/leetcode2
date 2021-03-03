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

class Solution {
public:
    int countNodes(TreeNode *root) {
        vector<TreeNode *> stack;
        TreeNode *pre = root;
        int layer = 0;
        int num = 0;
        int flag = 0;

        while (pre != nullptr || stack.size() > 0) {
            while (pre != nullptr) {
                stack.push_back(pre);
                if (pre->left != nullptr) {
                    pre = pre->left;
                } else {
                    pre = pre->right;
                }
            }
            if (flag == 0) {
                layer = stack.size();
                num += 1;
                flag = 1;
            } else {
                if (layer == stack.size()) {
                    num += 1;
                } else {
                    break;
                }
            }
            TreeNode *tail = stack[stack.size() - 1];
            stack.pop_back();
            while (stack.size() > 0) {
                TreeNode *tail2 = stack[stack.size() - 1];
                stack.pop_back();
                if (tail == tail2->left) {
                    stack.push_back(tail2);
                    pre = tail2->right;
                    break;
                } else {
                    tail = tail2;
                }
            }
        }

        if (layer == 0) {
            return 0;
        } else {
            return pow(2, layer - 1) - 1 + num;
        }

    }
};