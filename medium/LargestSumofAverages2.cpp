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
    double m[101][101] = {};

    double largestSumOfAverages1(vector<int> &A, int K, int p = 0) {
        if (p >= A.size() || m[K][p] > 0) return m[K][p];
        for (double i = p, sum = A[p]; i <= A.size() - K; sum += A[++i])
            m[K][p] = max(m[K][p],
                          K == 1 && i < A.size() - 1 ? 0 : sum / (i - p + 1) + largestSumOfAverages1(A, K - 1, i + 1));
        return m[K][p];
    }

    double largestSumOfAverages(vector<int> &A, int K) {
        return largestSumOfAverages1(A, K, 0);

    }
};