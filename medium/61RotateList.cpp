//
// Created by 宋峰 on 2019/4/22.
//
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        int n = 0;
        ListNode *p = head;
        if (p == nullptr) {
            return head;
        }
        while (p->next != nullptr) {
            n += 1;
            p = p->next;
        }
        int m = n + 1 - k % (n + 1);
        p->next=head;
        int i=0;
        while (i<m){
            p=p->next;
            i+=1;
        }
        ListNode *result = p->next;
        p->next= nullptr;

        return result;
    }
};