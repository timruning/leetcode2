//
// Created by timruning on 18-5-11.
//

#include "../import_iostream.h"

void printVec(const vector<int> &vec) {
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
}