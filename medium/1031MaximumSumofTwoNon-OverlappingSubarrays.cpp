//
// Created by 宋峰 on 2021/3/11.
//
#include <vector>

using namespace std;

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int> &A, int L, int M) {
        vector<int> l(A.size(), A[0]);
        vector<int> m(A.size(), A[0]);
        for (int i = 1; i < A.size(); i++) {
            l[i] = l[i - 1] + A[i];
            m[i] = m[i - 1] + A[i];
            if (i >= L) {
                l[i] -= A[i - L];
            }
            if (i >= M) {
                m[i] -= A[i - M];
            }
        }
        int result = l[L - 1] + m[m.size() - 1];
        for (int i = L - 1; i < l.size(); i++) {
            for (int j = M - 1; j < l.size(); j++) {
                if ((i - j >= L || j - i >= M) && l[i] + m[j] > result) {
                    result = l[i] + m[j];
                }
            }
        }
        return result;
    }
};