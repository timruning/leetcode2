//
// Created by timruning on 2019/4/9.
//

#include <iostream>
#include <vector>
#include "../tree/tree.cpp"
#include <stack>
using namespace std;

void pre_order(TreeNode* root){
    TreeNode* pre = root;
    stack<TreeNode*> stk;
    while (pre!= nullptr || !stk.empty()){
        while (pre!= nullptr){
            stk.push(pre);
            cout<< pre->val<<" ";
            pre= pre->left;
        }
        TreeNode* tail =stk.top();
        stk.pop();
        pre = tail->right;
    }
}

void mid_order(TreeNode* root){
    TreeNode* pre = root;
    stack<TreeNode*> stk;
    while (pre!= nullptr || !stk.empty()){
        while (pre!= nullptr){
            stk.push(pre);
            pre= pre->left;
        }
        TreeNode* tail =stk.top();
        cout<< tail->val<<" ";
        stk.pop();
        pre = tail->right;
    }
}

void back_order(TreeNode* root){
    TreeNode* pre = root;
    stack<TreeNode*> stk;
    while (pre!= nullptr || !stk.empty()){
        while (pre!= nullptr){
            stk.push(pre);
            if(pre->left!= nullptr){
                pre= pre->left;
            }else{
                pre=pre->right;
            }
        }
        TreeNode* tail1 =stk.top();
        cout<<tail1->val<<" ";
        stk.pop();
        while (!stk.empty()){
            TreeNode* tail2 = stk.top();
            if(tail1== tail2->right){
                stk.pop();
                tail1= tail2;
                cout<<tail1->val<<" ";
            }else{
                pre = tail2->right;
                break;
            }
        }
    }
}

vector<int> print_test(int a[],int begin,int end){
    vector<int> vec;
    for(int i=begin;i<=end;i++){
        vec.push_back(a[i]);
    }
    return vec;
}
int split(int a[], int begin, int end){
    int index = begin;
    for(int i=begin+1;i<=end;i++){
        if(a[i]>a[index]){
            int tmp =a[i];
            a[i]=a[end];
            a[end]=tmp;
            end--;
            i--;
        }
    }
    int tmp = a[index];
    a[index] = a[end];
    a[end]= tmp;
    index = end;
    return index;
}

void qsort(int a[], int begin, int end) {
    if(begin>=end){
        return;
    }
    int index = split(a,begin,end);
    qsort(a,begin,index-1);
    qsort(a,index+1,end);
}

void just(int *a, int begin, int end){
    int pre = begin;
    while (pre<=end){
        int mx = pre;
        int left = 2*pre+1;
        int right = 2*pre+2;
        if(left<=end && a[left]> a[mx]){
            mx= left;
        }
        if(right<=end && a[right]>a[mx]){
            mx = right;
        }
        if(mx!=pre){
            int tmp = a[mx];
            a[mx] = a[pre];
            a[pre]=tmp;
            pre =mx;
        }else{
            break;
        }
    }
}

void build_heap(int *a, int begin, int end){
    for(int i = (begin+end)/2;i>=begin;i--){
        just(a,i,end);
    }
}

void heap_sort(int a[], int begin, int end){
    build_heap(a,begin,end);
    for(int i=end;i>=begin;i--){
        int tmp =a[i];
        a[i]=a[begin];
        a[begin] = tmp;
        just(a,begin,i-1);
    }
}