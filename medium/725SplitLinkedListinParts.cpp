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
    int getListSize(ListNode *root) {
        int n = 0;
        ListNode *p = root;
        while (p != NULL) {
            n++;
            p = p->next;
        }
        return n;
    }

    vector<ListNode *> splitListToParts(ListNode *root, int k) {
        int size = getListSize(root);
        int a = size / k;
        int b = size % k;
        vector<ListNode *> result;
        ListNode *p = root;
        while (k > 0) {
            int c = a;
            if (b > 0) {
                c += 1;
                b--;
            }
            result.push_back(p);
            while (p != NULL && c > 1) {
                p = p->next;
                c--;
            }
            if (p != NULL) {
                ListNode *x = p->next;
                p->next = NULL;
                p = x;
            }
            k--;
        }
        return result;
    }
};