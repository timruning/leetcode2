//
// Created by 宋峰 on 2021/12/1.
//

#include <iostream>
#include <vector>
#include <set>
#include <stack>

using namespace std;

class Node {
public:
    Node *left;
    Node *right;
    int val;

    Node(int x) {
        this->val = x;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void pre_order(Node *root) {
    Node *pre = root;
    stack<Node *> sta;
    while (pre != nullptr || sta.size() != 0) {
        while (pre != nullptr) {
            sta.push(pre);
            cout << pre->val << endl;
            pre = pre->left;
        }
        if (sta.size() > 0) {
            Node *tail = sta.top();
            sta.pop();
            pre = tail->right;
        }
    }
}

void mid_order(Node *root) {
    Node *pre = root;
    stack<Node *> sta;
    while (pre != nullptr || sta.size() != 0) {
        while (pre != nullptr) {
            sta.push(pre);
            pre = pre->left;
        }
        if (sta.size() > 0) {
            Node *tail = sta.top();
            cout << tail->val << endl;
            sta.pop();
            pre = tail->right;
        }
    }
}

void back_order(Node *root) {
    Node *pre = root;
    stack<Node *> sta;
    while (pre != nullptr || sta.size() != 0) {
        while (pre != nullptr) {
            sta.push(pre);
            if (pre->left != nullptr) {
                pre = pre->left;
            } else {
                pre = pre->right;
            }

        }
        if (sta.size() > 0) {
            Node *tail1 = sta.top();
            cout << tail1->val << endl;
            sta.pop();
            while (sta.size() > 0) {
                Node *tail2 = sta.top();
                if (tail1 == tail2->left) {
                    pre = tail2->right;
                    break;
                } else {
                    tail1 = tail2;
                    cout << tail1->val << endl;
                    sta.pop();
                }
            }
        }
    }
}

int main() {

}