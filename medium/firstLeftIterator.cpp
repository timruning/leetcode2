//
// Created by timruning on 18-8-27.
//
#include <vector>
#include <iostream>

using namespace std;

class tree {
public:
    vector<int> findX(int tree[], int num, int X) {
        int root = 0;
        vector<int> stack;
        vector<int> result;
        stack.push_back(root);
        result.push_back(tree[root]);
        int label = 0;
        while (stack.size() > 0) {
            int top = stack[stack.size() - 1];
            if (tree[top] == X) {
                break;
            }
            if (label == 0) {
                int left = 2 * top + 1;
                if (left < num && tree[left] != -1) {
                    stack.push_back(left);
                    result.push_back(tree[left]);
                    label = 0;
                } else {
                    label = 1;
                }
            } else if (label == 1) {
                int right = 2 * top + 2;
                if (right < num && tree[right] != -1) {
                    stack.push_back(right);
                    result.push_back(tree[right]);
                    label = 0;
                } else {
                    label = 2;
                }
            } else {
                stack.pop_back();
                int top1 = stack[stack.size() - 1];
                if (top == 2 * top1 + 1) {
                    label = 1;
                } else if (top == 2 * top1 + 2) {
                    label = 2;
                } else {
                    for (int i = 0; i < stack.size(); i++) {
                        cout << stack[i] << " ";
                    }
                    cout << endl;
                    return stack;
                }
            }
        }
        return stack;
    }

    vector<int> firstLeftIterator(int tree[], int num) {
        int root = 0;
        vector<int> stack;
        vector<int> result;
        stack.push_back(root);
        result.push_back(tree[root]);
        int label = 0;
        while (stack.size() > 0) {
            int top = stack[stack.size() - 1];
            if (label == 0) {
                int left = 2 * top + 1;
                if (left < num && tree[left] != -1) {
                    stack.push_back(left);
                    result.push_back(tree[left]);
                    label = 0;
                } else {
                    label = 1;
                }
            } else if (label == 1) {
                int right = 2 * top + 2;
                if (right < num && tree[right] != -1) {
                    stack.push_back(right);
                    result.push_back(tree[right]);
                    label = 0;
                } else {
                    label = 2;
                }
            } else {
                stack.pop_back();
                int top1 = stack[stack.size() - 1];
                if (top == 2 * top1 + 1) {
                    label = 1;
                } else if (top == 2 * top1 + 2) {
                    label = 2;
                } else {
                    for (int i = 0; i < stack.size(); i++) {
                        cout << stack[i] << " ";
                    }
                    cout << endl;
                    return result;
                }
            }
        }
        return result;
    }
};
