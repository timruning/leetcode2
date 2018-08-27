//
// Created by timruning on 18-8-27.
//

#include <iostream>
#include "../medium/firstLeftIterator.cpp"

using namespace std;

int main() {
    int t[] = {0, 1, 2, 3, 4, 5, -1, -1, 8};
    tree *x = new tree;
    vector<int> result = x->findX(t, 9, 5);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}