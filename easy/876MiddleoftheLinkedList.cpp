//
// Created by timruning on 2020/4/18.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include "../import_iostream.h"

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *middleNode(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
            if (fast->next != NULL) {
                fast = fast->next;
            } else {
                break;
            }
        }
        return slow;
    }
};