//
// Created by timruning on 18-9-5.
//

#include <iostream>
#include "../tree/tree.cpp"

using namespace std;

int main() {
    int a[] = {
            3, 5, 1, 6, 2, 0, 8, null, null, 7, 4
    };
    TreeNode *root = buildTree(a, sizeof(a) / sizeof(int));
    cout << "hello" << endl;
}