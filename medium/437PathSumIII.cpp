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
int null = (int) (0x80000001);

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
    int check(vector<TreeNode *> stack, TreeNode *tail, int sum) {
        int total = tail->val;
        int result = 0;
        for (int i = stack.size() - 1; i >= 0; i--) {
            if (total == sum) {
                result += 1;
            }
            total += stack[i]->val;
        }
        if (total == sum) {
            return result + 1;
        } else {
            return result;
        }
    }

    int pathSum(TreeNode *root, int sum) {
        vector<TreeNode *> stack;
        TreeNode *pre = root;
        int result = 0;
        while (pre != NULL || stack.size() > 0) {
            while (pre != NULL) {
                stack.push_back(pre);
                if (pre->left != NULL) {
                    pre = pre->left;
                } else {
                    pre = pre->right;
                }
            }
            TreeNode *tail = stack[stack.size() - 1];
            stack.pop_back();
            result += check(stack, tail, sum);

            while (stack.size() > 0) {
                TreeNode *tail2 = stack[stack.size() - 1];
                stack.pop_back();
                if (tail == tail2->left) {
                    stack.push_back(tail2);
                    pre = tail2->right;
                    break;
                } else {
                    tail = tail2;
                    result += check(stack, tail, sum);
                }
            }
        }
        return result;
    }
};