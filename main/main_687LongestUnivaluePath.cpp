//
// Created by 宋峰 on 2021/2/26.
//

#include <vector>
#include <iostream>
#include "../medium/687LongestUnivaluePath.cpp"
using namespace std;

int main(){
    int nodes[]={5,4,5,1,1,5};
    TreeNode* root = buildTree(nodes,7);
    Solution sol;
    int n = sol.longestUnivaluePath(root);
    cout<<n<<endl;
}