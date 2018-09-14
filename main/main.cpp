#include <iostream>
#include "../tree/tree.cpp"
#include <vector>

using namespace std;

int main() {
    int a[] = {0, 1, 2, -1, 3, 4, 5, -1, -1, -1, 6, -1, -1, 7};
    node *root = buildTree(a, 14);
    for (int i = 0; i < 10; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "hello\t" << root->value << endl;
}