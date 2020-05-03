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
    int numComponents(ListNode *head, vector<int> &G) {
        unordered_set<int> G1;
        for (auto v:G) {
            G1.insert(v);
        }
        int result = 0;
        ListNode *p = head;
        bool flag = true;
        while (p != NULL) {
            if (G1.find(p->val) != G1.end()) {
                if(flag){
                    flag=false;
                    result+=1;
                }
            }else{
                flag=true;
            }
            p=p->next;
        }
        return result;
    }
};