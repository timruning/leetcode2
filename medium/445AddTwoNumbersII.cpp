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
    ListNode *reverseList(ListNode *head) {
        ListNode *head1 = NULL;
        while (head != NULL) {
            ListNode *p = head;
            head = head->next;
            p->next = head1;
            head1 = p;
        }
        return head1;
    }

    ListNode *add(ListNode *l1, ListNode *l2) {
        int a = 0;
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *result = NULL;
        while (p1 != NULL && p2 != NULL) {
            int sum = p1->val + p2->val + a;
            ListNode *node = new ListNode(sum % 10);
            a = sum / 10;
            node->next = result;
            result = node;
            p1=p1->next;
            p2=p2->next;
        }
        while (p1 != NULL) {
            int sum = p1->val + a;
            ListNode *node = new ListNode(sum % 10);
            a = sum / 10;
            node->next = result;
            result = node;
            p1=p1->next;
        }
        while (p2 != NULL) {
            int sum = p2->val + a;
            ListNode *node = new ListNode(sum % 10);
            a = sum / 10;
            node->next = result;
            result = node;
            p2=p2->next;
        }
        while (a > 0) {
            int sum = a;
            ListNode *node = new ListNode(sum % 10);
            a = sum / 10;
            node->next = result;
            result = node;
        }
        return result;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *l1r = reverseList(l1);
        ListNode *l2r = reverseList(l2);
        return add(l1r, l2r);
    }
};