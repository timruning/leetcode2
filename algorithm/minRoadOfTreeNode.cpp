//
// Created by 宋峰 on 2018/8/27.
//
#include "../tree/tree.h"
#include <vector>

using namespace std;

class minLengthOfTreeNode {
    vector<node *> findNode(tree *t, node *a) {
        vector<node*> stack;
        node* root=t->root;
        if(root== nullptr){
            return stack;
        }
        stack.push_back(root);
        int label=0;
        while (true){
            node* top=stack[stack.size()-1];
            if(label==0){
                if(){

                }
            }
        }
    }

    int getMinLengthOfTreeNode(tree *t, node *a, node *b) {
        vector<node *> aPath = findNode(t, a);
        vector<node *> bPath = findNode(t, b);
        int i = 0;
        while (i < aPath.size() && i < bPath.size() && aPath[i]->value == bPath[i]->value) {
            i+=1;
            aPath.erase(aPath.begin());
            bPath.erase(bPath.begin());
        }
        return aPath.size()+bPath.size();
    }
};

