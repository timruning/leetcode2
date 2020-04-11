//
// Created by timruning on 19-4-8.
//

#include <iostream>

using namespace std;

int split(int *a, int begin, int end) {
    int i = begin - 1;
    int j = begin;
    int st = a[end - 1];
    while (j < end - 1) {
        if (a[j] < st) {
            i += 1;
            int tmp = a[j];
            a[j] = a[i];
            a[i] = tmp;
        }
        j += 1;
    }
    int tmp = a[i + 1];
    a[i + 1] = a[end - 1];
    a[end - 1] = tmp;
    return i + 1;
}

void qsort(int *a, int begin, int end) {
    int position = split(a, begin, end);
    if (begin < position)
        qsort(a, begin, position);
    if (position < end - 1)
        qsort(a, position, end);
}

void adjust_heap(int *a, int begin, int end) {
    int left = begin * 2 + 1;
    int right = begin * 2 + 2;

    int max = begin;
    if (left <= end && a[begin] < a[left]) {
        max = left;
    }
    if (right <= end && a[max] < a[right]) {
        max = right;
    }
    if (max != begin) {
        int tmp = a[begin];
        a[begin] = a[max];
        a[max] = tmp;
        adjust_heap(a, max, end);
    }
}


void build_heap(int *a, int begin, int end) {
    int midel = (begin + end) / 2;
    for (int i = midel; i >= begin; i--) {
        adjust_heap(a, i, end);
    }
}

void heap_sort(int *a, int begin, int end) {
    build_heap(a, begin, end);
    for (int j = begin; j <= end; ++j) {
        cout << " " << a[j];
    }
    cout << endl;
    for (int i = end; i >= begin; i--) {
        adjust_heap(a, begin, i);
        int tmp = a[i];
        a[i] = a[begin];
        a[begin] = tmp;

    }
}