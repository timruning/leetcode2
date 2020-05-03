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
    void deleteList(ListNode *head, ListNode *p, unordered_map<ListNode *, int> n, unordered_map<int, ListNode *>& m) {
        while (head != NULL && head != p) {
            ListNode *x = head;
            head = head->next;
            unordered_map<ListNode *, int>::iterator  iter1 = n.find(x);
            if(iter1!=n.end()){
                int sum=iter1->second;
                unordered_map<int, ListNode *>::iterator node = m.find(sum);
                if (node != m.end() && node->second == x) {
                    m.erase(node);
                }
                delete (x);
            }
        }
    }

    ListNode *removeZeroSumSublists(ListNode *head) {
        unordered_map<int, ListNode *> m;
        unordered_map<ListNode *, int> n;
        ListNode *p = head;
        int sum = 0;
        while (p != NULL) {
            sum += p->val;
            n.insert(make_pair(p, sum));
            if (sum == 0) {
                p = p->next;
                deleteList(head, p, n, m);
                head = p;
            } else {
                unordered_map<int, ListNode *>::iterator iter = m.find(sum);
                if (iter == m.end()) {
                    m.insert(make_pair(sum, p));
                    p = p->next;
                } else {
                    p = p->next;
                    ListNode *t = iter->second;
                    deleteList(t->next, p, n, m);
                    t->next = p;
                }
            }

        }
        return head;
    }

    ListNode *removeZeroSumSublists2(ListNode *head) {
        unordered_map<int, ListNode *> m;
        ListNode *p = head;
        int sum = 0;
        while (p != NULL) {
            sum += p->val;
            if (sum == 0) {
                p = p->next;
                head = p;
            } else {
                unordered_map<int, ListNode *>::iterator iter = m.find(sum);
                if (iter == m.end()) {
                    m.insert(make_pair(sum, p));
                    p = p->next;
                } else {
                    p = p->next;
                    ListNode *t = iter->second;
                    t->next = p;
                }
            }

        }
        return head;
    }
};