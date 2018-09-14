//
// Created by 宋峰 on 2018/8/27.
//
#include <vector>

using namespace std;

class node {
public:
    int value;
    node *left;
    node *right;
    node(){
        value= -1;
        left=nullptr;
        right=nullptr;
    }
    node(int i) {
        value = i;
        left=nullptr;
        right=nullptr;
    }
};

node *buildTree(int *a, int num) {
    node *root = nullptr;
    if (num < 1) {
        return root;
    }
    root = new node(a[0]);
    vector<node *> queue;
    queue.push_back(root);
    int i=0;
    while (queue.size()>0){
        if(i>=num){
            break;
        }
        int left=i+1;
        int right=i+2;
        node* node_left=nullptr;
        node* node_right=nullptr;
        if(left<num && a[left]!=-1){
            node_left=new node(a[left]);
        }
        if(right<num && a[right]!=-1){
            node_right=new node(a[right]);
        }
        node* father=queue[0];
        queue.erase(queue.begin());
        if(father!=nullptr){
            father->left=node_left;
            queue.push_back(node_left);
            father->right=node_right;
            queue.push_back(node_right);
        }

        i+=2;
    }
    return root;
}