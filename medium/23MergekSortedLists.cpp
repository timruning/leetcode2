//
// Created by 宋峰 on 2020/5/6.
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
    static bool my_func(ListNode *a, ListNode *b) {
        return a->val < b->val;
    }

    void insert(vector<ListNode *> heap, ListNode *a) {
        heap.push_back(a);
        int p = heap.size();
        while (p >= 0) {
            int child = p / 2 - 1;
            if (child >= 0 && heap[child]->val > heap[p]->val) {
                ListNode *tmp = heap[child];
                heap[child] = heap[p];
                heap[p] = tmp;
            } else {
                break;
            }
        }
    }

    ListNode *pop(vector<ListNode *> heap) {
        if (heap.size() <= 0) {
            return NULL;
        }
        ListNode *TMP = heap[heap.size() - 1];
        heap[heap.size() - 1] = heap[0];
        heap[0] = TMP;
        ListNode *tail = heap[heap.size() - 1];
        heap.pop_back();
        int p = 0;
        while (2 * p + 1 < heap.size()) {
            int left = 2 * p + 1;
            int right = 2 * p + 2;
            int t = p;
            if (left < heap.size() && heap[p]->val > heap[left]->val) {
                ListNode *tmp = heap[left];
                heap[left] = heap[p];
                heap[p] = tmp;
                t = left;
            }
            if (right < heap.size() && heap[p]->val > heap[right]->val) {
                ListNode *tmp = heap[right];
                heap[right] = heap[p];
                heap[p] = tmp;
                t = right;
            }
        }

        return tail;
    }

    void buildHeap(vector<ListNode *> heap) {
        int size = heap.size();

        for (int t = size / 2; t >= 0; t--) {
            int left = t * 2 + 1;
            int right = t * 2 + 2;

            if (left < size && heap[t]->val > heap[left]->val) {
                ListNode *tmp = heap[t];
                heap[t] = heap[left];
                heap[left] = tmp;
            }
            if (right < size && heap[t]->val > heap[right]->val) {
                ListNode *tmp = heap[t];
                heap[t] = heap[right];
                heap[right] = tmp;
            }
        }
    }

    ListNode *mergeKLists(vector<ListNode *> &lists) {

    }
};