#include "../import_iostream.h"


class MyLinkedList {
    struct ListNode {
        int val;
        ListNode *pre;
        ListNode *next;

        ListNode(int x) {
            val = x;
            pre = NULL;
            next = NULL;
        }
    };

    ListNode *head;
    ListNode *tail;
    int size;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        tail = NULL;
        head = NULL;
        size = 0;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index < size) {
            ListNode *p = head;
            while (index > 0) {
                p = p->next;
                index -= 1;
            }
            return p->val;
        } else {
            return -1;
        }
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode *p = new ListNode(val);
        if (size == 0) {
            tail = p;
            head = p;
        } else {
            p->next = head;
            head->pre = p;
            head = p;
        }
        size++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode *p = new ListNode(val);
        if (size == 0) {
            tail = p;
            head = p;
        } else {
            tail->next = p;
            p->pre = tail;
            tail = p;
        }
        size++;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        ListNode *node = new ListNode(val);
        ListNode *p = head;
        if (index == 0) {
            addAtHead(val);
        } else if (index == size) {
            addAtTail(val);
        } else if (index > 0 && index < size) {
            while (index > 0) {
                p = p->next;
                index--;
            }
            node->next = p;
            node->pre = p->pre;
            p->pre->next = node;
            p->pre = node;
            size++;
        }
    }

    void deleteHead() {
        if (size <= 0) {

        } else if (size == 1) {
            ListNode *node = head;
            head = NULL;
            tail = NULL;
            delete (node);
            size--;
        } else {
            ListNode *node = head;
            head = head->next;
            delete (node);
            size--;
        }
    }

    void deleteTail() {
        if (size <= 0) {

        } else if (size == 1) {
            ListNode *node = head;
            head = NULL;
            tail = NULL;
            delete (node);
            size--;
        } else {
            ListNode *node = tail;
            tail = tail->pre;
            delete (node);
            size--;
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0) {

        } else if (index == 0) {
            deleteHead();
        } else if (index == size - 1) {
            deleteTail();
        } else if (index > 0 && index < size) {
            ListNode *p = head;
            while (index > 0) {
                p = p->next;
                index--;
            }
            p->pre->next = p->next;
            p->next->pre = p->pre;
            delete (p);
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