//
// Created by timruning on 18-9-5.
//

#include <iostream>
#include "../algorithm/pre_order.cpp"
#include "../algorithm/sort.cpp"
using namespace std;

int main() {
    int a[] = {
            3, 5, 1, 6, 2, 0, 8, null, null, 7, 4
    };
    int a2[] = {
            3, 5, 1, 6, 2, 0, 8, null, null, 7, 4
    };
    TreeNode *root = buildTree(a, sizeof(a) / sizeof(int));
    preOrder(root);
    cout << "\n";
    middleOrder(root);
    cout << "\n";
    postOrder(root);
    cout << "\n";
    postOrder2(root);
    cout<<"\n";
    cout << "hello" << endl;
    qsort(a,3,8);
    for(int i=0;i<11;i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
    vector<int> vec2(a2,a2+11);
    heapsort(vec2,0,10);
    for(int i=0;i<11;i++){
        cout<<vec2[i]<<" ";
    }
}