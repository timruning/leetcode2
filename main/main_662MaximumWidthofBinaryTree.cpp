//
// Created by 宋峰 on 2021/2/26.
//

#include <vector>
#include <iostream>
#include "../medium/662MaximumWidthofBinaryTree.cpp"

int main(){
    cout<<"70"<<endl;
    int nodes[]={1,3,2,5,3,null,9};
    TreeNode* root=buildTree(nodes,7);
    Solution sol;
    int n=sol.widthOfBinaryTree(root);
    cout<<n<<endl;
}