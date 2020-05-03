//
// Created by timruning on 2020/5/3.
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
#include "../import_iostream.h"

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

    vector<int> nextLargerNodes(ListNode *head) {
        vector<pair<int, ListNode *>> stack;
        ListNode *p = head;
        vector<int> result;
        int i = 0;
        while (p != NULL) {
            stack.push_back(make_pair(i, p));
            result.push_back(0);
            i++;
            p = p->next;
            if (p == NULL) {
                break;
            }
            while (stack.size() > 0 && p->val > stack[stack.size() - 1].second->val) {
                result[stack[stack.size() - 1].first] = p->val;
                stack.pop_back();
            }
        }
        return result;
    }
};