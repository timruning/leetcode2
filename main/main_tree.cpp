//
// Created by timruning on 18-9-5.
//

#include <iostream>
//#include "../algorithm/tree_order2.cpp"
#include "../algorithm/sort3.cpp"
//#include "../algorithm/sort2.cpp"

using namespace std;

int main() {
    int b[]={0,34,1,43,1,4,5,6,66,5,2,1};
    heap_sort(b,0,11);
    for(int i=0;i<12;i++){
        cout<< b[i]<<" ";
    }

    cout<<endl;

//    qsort(b,5,10);
    for(int i=0;i<12;i++){
        cout<< b[i]<<" ";
    }
    cout<<endl;

    int a[] = {
            3, 5, 1, 6, 2, 0, 8, null, null, 7, 4
    };
    int a2[] = {
            3, 5, 1, 6, 2, 0, 8, null, null, 7, 4
    };
    TreeNode *root = buildTree(a, sizeof(a) / sizeof(int));
    pre_order(root);
    cout<<"\n";
    pre_order(root);
    cout << "\n";
    mid_order(root);
    cout << "mid_order\n";
    mid_order(root);
    cout << "mid_order\n";
    back_order(root);
    cout << "back_order\n";
    back_order(root);
    cout << "back_order\n";
    cout << "hello" << endl;
//    qsort(a, 3, 8);
    for (int i = 0; i < 11; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
    vector<int> vec2(a2, a2 + 11);
    cout<<"heap1"<<endl;
//    heapsort1(vec2, 0, 11);
//    for (int i = 0; i < 11; i++) {
//        cout << vec2[i] << " ";
//    }
//    cout<<"\n";
//    cout<<"heap"<<endl;
//    heapsort(vec2, 0, 10);
//    for (int i = 0; i < 11; i++) {
//        cout << vec2[i] << " ";
//    }
}