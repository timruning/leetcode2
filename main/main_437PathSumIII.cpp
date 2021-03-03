//
// Created by 宋峰 on 2021/3/2.
//

#include <vector>
#include <iostream>
#include "../medium/437PathSumIII.cpp"
using namespace std;


int main(){
    int nodes[]={10,5,-3,3,2,null,11,3,-2,null,1};
    TreeNode* root = buildTree(nodes,11);
    Solution sol;
    int n=sol.pathSum(root,8);
    cout<<n<<endl;
}