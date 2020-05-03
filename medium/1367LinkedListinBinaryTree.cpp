//
// Created by timruning on 2020/5/2.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

#include "../import_iostream.h"

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    bool checkNode(ListNode *head, TreeNode *root) {
        vector<TreeNode *> queue;
        TreeNode *p = root;
        ListNode *p2 = head;
        queue.push_back(p);
        while (p2 != NULL && queue.size() > 0) {
            p2 = p2->next;
            if (p2 == NULL) {
                return true;
            }
            int n = queue.size();
            for (int i = 0; i < n; i++) {
                TreeNode *node = queue[i];
                if (node->left != NULL && node->left->val == p2->val) {
                    queue.push_back(node->left);
                }
                if (node->right != NULL && node->right->val == p2->val) {
                    queue.push_back(node->right);
                }
            }
            queue.erase(queue.begin(), queue.begin() + n);
        }
        if(p2!=NULL)
            return false;
        else
            return true;
    }

    bool isSubPath(ListNode *head, TreeNode *root) {
        TreeNode *p = root;
        vector<TreeNode *> stack;
        if (head == NULL) {
            return true;
        }
        while (p != NULL || stack.size() > 0) {
            if (p != NULL) {
                if (p->val == head->val) {
                    bool flag = checkNode(head, p);
                    if (flag)
                        return flag;
                }
                stack.push_back(p);
                p = p->left;
            } else {
                p = stack[stack.size() - 1];
                stack.pop_back();
                p = p->right;
            }
        }
        return false;
    }
};