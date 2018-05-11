//
// Created by timruning on 18-5-11.
//813
//
/**
 *
 * medium
 * 813
 * */
#include "../import_iostream.h"

class LargestSumofAverages {
public:
    double largestSumOfAverages1(vector<int> &A, int k) {
        if (k == 1)
            return 1.0 * (A[A.size() - 1] - A[0]) / (A.size() - 1);
        double result = (A[k - 1] - A[0]) + 1.0 * (A[A.size() - 1] - A[k - 1]) / (A.size() - k);
        for (int i = 1; i < A.size() - k + 1; i++) {
            vector<int> tmpVec(A.begin() + i, A.end());
            double first = 1.0 * (A[i] - A[0]) / i;
            double second = largestSumOfAverages1(tmpVec, k - 1);
            result = result > (first + second) ? result : (first + second);
        }
        return result;
    }

    double largestSumOfAverages(vector<int> &A, int K) {
        vector<int> B;
        B.push_back(0);
        for (int i = 0; i < A.size(); i++) {
            int sum = B[i] + A[i];
            B.push_back(sum);
        }
        return largestSumOfAverages1(B, K);

    }
};