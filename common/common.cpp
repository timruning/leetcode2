//
// Created by timruning on 18-5-11.
//

#include "../import_iostream.h"

template<typename T>

void printVec(const vector<T> &vec) {
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
}

