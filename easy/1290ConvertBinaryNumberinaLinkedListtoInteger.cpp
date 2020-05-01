//
// Created by timruning on 2020/4/18.
//
#include "../import_iostream.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int getDecimalValue(ListNode *head) {
        int result = 0;
        while (head != NULL) {
            result = result * 2 + head->val;
            head = head->next;
        }
        return result;
    }
};