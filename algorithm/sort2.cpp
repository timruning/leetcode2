//
// Created by timruning on 2019/4/9.
//

#include <iostream>
using namespace std;

int split(int *a,int begin,int end){
    int i=begin-1;
    int j=begin;
    int st=a[end];
    while (j<end){
        if(a[j]<st){
            i+=1;
            int tmp=a[i];
            a[i]=a[j];
            a[j]=tmp;
        }
        j+=1;
    }
    i+=1;
    int tmp=a[i];
    a[i]=a[j];
    a[j]=tmp;
    return i;
}

void qsort2(int *a,int begin,int end){
    int i=split(a,begin,end);
    if(begin<i){
        qsort2(a,begin,i-1);
    }
    if(i<end){
        qsort2(a,i+1,end);
    }
}

void adjust_heap(int *a,int begin,int end){
    int left=begin*2+1;
    int right=begin*2+2;
    int max=begin;
    if(left<=end && a[left]>a[max]){
        max=left;
    }
    if(right<=end && a[right]>a[max]){
        max=right;
    }
    if (max != begin) {
        int tmp = a[max];
        a[max] = a[begin];
        a[begin] = tmp;
        adjust_heap(a, max, end);
    }
}

void build_heap(int *a,int begin,int end){
    for(int i=(begin+end)/2;i>=begin;i--){
        adjust_heap(a,i,end);
    }
}

void heap_sort(int *a,int begin,int end){
    build_heap(a,begin,end);
    for(int i=end;i>=begin;i--){
        adjust_heap(a,begin,i);
        int tmp=a[i];
        a[i]=a[begin];
        a[begin]=tmp;
    }
}