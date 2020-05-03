//
// Created by timruning on 2020/5/1.
//
#include "../import_iostream.h"

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }

};

class Solution {
public:
    Node *copyNode(Node *head) {
        Node *result = new Node(head->val);
        result->next = head->next;
        result->random = head->random;
        return result;
    }

    Node *copyRandomList(Node *head) {
        if (head == NULL) {
            return head;
        }
        unordered_map<Node*,Node*> mem;
        Node *p = head;
        while (p!=NULL){
            Node *node = copyNode(p);
            mem.insert(make_pair(p,node));
            p=p->next;
        }

        Node *r = head;
        while (r!=NULL){
            Node *r1 = mem.find(r)->second;
            if(r->next!=NULL)
                r1->next= mem.find(r->next)->second;
            if(r->random!=NULL)
                r1->random= mem.find(r->random)->second;
            r=r->next;
        }

        return mem.find(head)->second;;
    }
};