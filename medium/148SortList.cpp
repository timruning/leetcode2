//
// Created by timruning on 2020/5/1.
//

#include "../import_iostream.h"

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

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *split(ListNode *head, ListNode *tail) {
        ListNode *head2 = head;
        ListNode *p = head;
        if (p == NULL) {
            return p;
        }
        while (p->next != tail) {
            if (head->val > p->next->val) {
                ListNode *tmp = p->next;
                p->next = tmp->next;
                tmp->next = head2;
                head2 = tmp;
            } else {
                p = p->next;
            }
        }
        return head2;
    }

    ListNode *qsortList(ListNode *head, ListNode *tail) {
        if (head == tail) {
            return head;
        }
        ListNode *head1 = split(head, tail);
        ListNode *head2=head;
        if(head1!=head){
            head2=qsortList(head1,head);
        }
        if(head!=NULL){
            ListNode *head3=qsortList(head->next,NULL);
            head->next=head3;
        }
        return head2;
    }

    ListNode *sortList(ListNode *head) {
        ListNode *x = qsortList(head, NULL);
        return x;
    }

    ListNode *getList(vector<int> vec) {
        if (vec.size() == 0) {
            return NULL;
        }
        ListNode *head = new ListNode(vec[0]);
        ListNode *p = head;
        for (int i = 1; i < vec.size(); i++) {
            ListNode *node = new ListNode(vec[i]);
            p->next = node;
            p = node;
        }
        return head;
    }

    ListNode *sortList_all(ListNode *head) {
        vector<int> vec;
        while (head != NULL) {
            vec.push_back(head->val);
            head = head->next;
        }
        sort(vec.begin(), vec.end());
        return getList(vec);
    }
};