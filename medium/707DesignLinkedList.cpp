//
// Created by timruning on 2020/4/18.
//

#include "../import_iostream.h"

class node {
public:
    int val;
    node *next;
    node *pre;

    node(int x) {
        val = x;
        next = NULL;
        pre = NULL;
    }
};

class MyLinkedList {
public:
    node *head;
    node *tail;
    int size;

    /** Initialize your data structure here. */
    MyLinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        node *p = head;
        for (int i = 0; i < index; i++) {
            if (p != NULL) {
                p = p->next;
            }
        }
        if (p == NULL) {
            return -1;
        } else {
            return p->val;
        }
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        addAtIndex(0,val);
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        addAtIndex(size,val);
    }

    /** Add a node of value val before the index-th node in the linked list.
     * If index equals to the length of linked list, the node will be appended to the end of linked list.
     * If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        node *p = new node(val);
        node *pt = head;
        if (index == 0) {
            if (head == NULL) {
                tail = p;
                head = p;
                size += 1;
            } else {
                p->next = head;
                head->pre = p;
                head = p;
                size++;
            }
        } else if (index == size) {
            tail->next = p;
            p->pre = tail;
            tail = p;
            size += 1;
        } else if (index < size) {
            for (int i = 0; i < index; i++) {
                pt = pt->next;
            }
            p->next = pt;
            p->pre = pt->pre;
            pt->pre->next = p;
            pt->pre = p;
            size += 1;
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        node *pt = head;
        if (index == 0) {
            if (size == 0) {

            } else if (size == 1) {
                head = NULL;
                tail = NULL;
                delete (pt);
                size--;
            } else {
                head = head->next;
                head->pre = NULL;
                delete (pt);
                size--;
            }
        }  else if (index < size) {
            for (int i = 0; i < index; i++) {
                pt = pt->next;
            }
            pt->pre->next = pt->next;
            if(pt->next!=NULL){
                pt->next->pre = pt->pre;
            }
            delete (pt);
            size--;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */