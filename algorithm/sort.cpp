//
// Created by 宋峰 on 2018/9/24.
//

#include <vector>
#include <iostream>

using namespace std;

int partition(int vec[], int begin, int end) {
    int i = begin - 1;
    int j = begin;
    int x = vec[end];
    while (j < end) {
        if (vec[j] < x) {
            i += 1;
            int tmp = vec[i];
            vec[i] = vec[j];
            vec[j] = tmp;
        }
        j += 1;
    }
    int tmp = vec[i + 1];
    vec[i + 1] = vec[end];
    vec[end] = tmp;
    return i + 1;
}

void qsort(int vec[], int begin, int end) {
    if (begin >= end) {
        return;
    }
    int k = partition(vec, begin, end);
    qsort(vec, begin, k - 1);
    qsort(vec, k + 1, end);
}

void adjustHeap(vector<int>& vec, int begin, int end) {
    int top = begin;
    int x = vec[top];
    int left = top * 2 + 1;
    int right = top * 2 + 2;
    int max_index = top;
    if (left <= end && vec[left] > x) {
        max_index = left;
    }
    if (right <= end && vec[right] > vec[max_index]) {
        max_index = right;
    }
    if (max_index != top) {
        int tmp = vec[max_index];
        vec[max_index] = vec[top];
        vec[top] = tmp;
        adjustHeap(vec, max_index, end);
    }
}

void buildheap(vector<int>& vec, int begin, int end) {
    for (int i = (end + begin) / 2; i >= begin; i--) {
        adjustHeap(vec, i, end);
    }
}

void heapsort(vector<int>& vec, int begin, int end) {
    buildheap(vec,begin,end);
    for(int i=end;i>=begin;i--){
        adjustHeap(vec,begin,i);
        int tmp=vec[begin];
        vec[begin]=vec[i];
        vec[i]=tmp;
    }
}