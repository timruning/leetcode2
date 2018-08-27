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
    double tmpMem[200][200];

    double largestSumOfAverages1(vector<int> &A, int mem[], int n, int k) {
        if (tmpMem[n - 1][k - 1] != 0) {
            return tmpMem[n - 1][k - 1];
        }
        for (int i = 0; i < n; i++) {
            tmpMem[0][i] = 1.0 * mem[i + 1] / (i + 1);
        }
        for (int j = 1; j < k; k++) {
            for (int i = j; i < n; i++) {
                if (i == j) {
                    return A[i] + largestSumOfAverages1(A, mem, i - 1, j - 1);
                } else {
                    int gap = i - j + 1;
                    double result = 0;
                    for (int t = 1; t < gap; t++) {
                        double first = (mem[i + 1] - mem[i + 1 - t]) / t;
                        double second = largestSumOfAverages1(A, mem, i + 1 - t, j - 1);
                        if (result < (first + second))
                            result = first + second;
                    }
                    tmpMem[j][i] = result;
                }
            }
        }
        return tmpMem[n - 1][k - 1];
    }

    double largestSumOfAverages(vector<int> &A, int K) {
        int n = A.size();
        int mem[n + 1];
        memset(mem, 0, sizeof(mem));
        for (int i = 0; i < n; i++) {
            mem[i + 1] = mem[i] + A[i];
        }
        memset(tmpMem, 0, sizeof(tmpMem));
        return largestSumOfAverages1(A, mem, n, K);
    }
};