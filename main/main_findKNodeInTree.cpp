//
// Created by 宋峰 on 2018/9/21.
//

#include <vector>
#include <iostream>
#include "../algorithm/findKInSearchTree.cpp"
using namespace std;

int main(){
    int a[]={5,2,7,1,3,6,8,null,null,null,4};
    int b[]={20,3,24,null,5,22,30,null,null,null,9,null,null,null,null,null,null,null,null,null,null,7,10};
    TreeNode* root=buildTree (b, sizeof(b)/ sizeof(int));
    int k=findKNodeInTree(root,7);
    cout<<endl;
    cout<<k<<endl;
}
