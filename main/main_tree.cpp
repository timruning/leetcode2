//
// Created by timruning on 18-9-5.
//

#include <iostream>
#include "../algorithm/tree_order2.cpp"
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
    pre_order1(root);
    cout<<"\n";
    pre_order(root);
    cout << "\n";
    mid_order1(root);
    cout << "mid_order1\n";
    mid_order(root);
    cout << "mid_order\n";
    post_order1(root);
    cout << "post_order1\n";
    post_order(root);
    cout << "post_order\n";
    cout << "hello" << endl;
    qsort(a, 3, 8);
    for (int i = 0; i < 11; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
    vector<int> vec2(a2, a2 + 11);
    cout<<"heap1"<<endl;
    heapsort1(vec2, 0, 11);
    for (int i = 0; i < 11; i++) {
        cout << vec2[i] << " ";
    }
    cout<<"\n";
    cout<<"heap"<<endl;
    heapsort(vec2, 0, 10);
    for (int i = 0; i < 11; i++) {
        cout << vec2[i] << " ";
    }
}