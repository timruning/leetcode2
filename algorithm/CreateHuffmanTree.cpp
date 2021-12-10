//
// Created by 宋峰 on 2021/12/7.
//

#include <vector>
#include <iostream>

using namespace std;

class HuffmanTree {
public:
    static bool comp(int a, int b) {
        return a > b;
    }

    vector<int> nodes;
    vector<int> parent;
    vector<int> binary;

    HuffmanTree(vector<int> vec) {
        sort(vec.begin(), vec.end(), comp);
        nodes = vector<int>(2 * vec.size() + 1, 1e15);
        parent = vector<int>(2 * vec.size() + 1, -1);
        binary = vector<int>(2 * vec.size() + 1, 0);
        int min1i, min2i;
        for (int i = 0; i < vec.size(); i++) {
            nodes[i] = vec[i];
        }

        int pos1 = vec.size() - 1;
        int pos2 = vec.size();
        for (int a = 0; a < vec.size(); a++) {
            if (pos1 >= 0) {
                if (nodes[pos1] < nodes[pos2]) {
                    min1i = pos1;
                    pos1--;
                } else {
                    min1i = pos2;
                    pos2++;
                }
            } else {
                min1i = pos2;
                pos2++;
            }
            if (pos1 >= 0) {
                if (nodes[pos1] < nodes[pos2]) {
                    min2i = pos1;
                    pos1--;
                } else {
                    min2i = pos2;
                    pos2++;
                }
            } else {
                min2i = pos2;
                pos2++;
            }
            nodes[vec.size() + a] = nodes[min1i] + nodes[min2i];
            parent[min1i] = vec.size() + a;
            parent[min2i] = vec.size() + a;
            binary[min2i] = 1;
        }
    }

    vector<int> getCode(int x) {
        vector<int> result;
        while (1) {
            result.insert(result.begin(), binary[x]);
            x = parent[x];
            if (x == binary.size() - 2) {
                break;
             }
        }
        return result;
    }
};

int main() {
    vector<int> vec = {7, 6, 5, 4, 3, 2, 1};
    HuffmanTree tree = HuffmanTree(vec);
    vector<int> result = tree.getCode(2);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
}