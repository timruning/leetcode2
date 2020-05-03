//
// Created by timruning on 2020/5/3.
//

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
#include "../import_iostream.h"

class Node {
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

class Solution {
public:
    Node *flatten(Node *head) {
        if(head==NULL){
            return head;
        }
        vector<Node *> stack;
        vector<Node *> list;
        Node *p = head;
        while (p != NULL || stack.size() > 0) {
            if (p != NULL) {
                stack.push_back(p);
                list.push_back(p);
                p = p->child;
            } else {
                p = stack[stack.size() - 1];
                p = p->next;
                stack.pop_back();
            }
        }
        p = head;
        for(int i=1;i<list.size();i++){
            p->next=list[i];
            list[i]->prev=p;
            list[i]->child=NULL;
            p=list[i];
        }
        head->prev=NULL;
        head->child=NULL;
        list[list.size()-1]->next=NULL;
        return head;
    }
};