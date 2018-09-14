//
// Created by 宋峰 on 2018/9/2.
//
#include <vector>

using namespace std;

class Solution {
public:
    bool isIdealPermutation(vector<int> &A) {
        int size = A.size();
        if(size<=2){
            return true;
        }
        int max=A[0];
        int begin=0;
        for(int i=2;i<size;i++){
            if(A[i-2]>max){
                max=A[i-2];
            }
            if(A[i]<max)
                return false;
        }
        return true;
    }
};