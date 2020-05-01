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
    void reorderList(ListNode *head) {
        if(head==NULL || head->next==NULL){
            return;
        }
        vector<ListNode *> a;
        ListNode *p = head;
        while (p != NULL) {
            a.push_back(p);
            p = p->next;
        }
        int size = a.size();
        int t = size - 1;
        p = head;
        while (t >= size / 2) {
            ListNode *node = a[t];
            node->next = p->next;
            p->next = node;
            p = node->next;
            t--;
        }
        p->next = NULL;
    }
};