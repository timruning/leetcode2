//
// Created by 宋峰 on 2018/9/25.
//
#include <vector>
#include <string>
#include "../import_iostream.h"

using namespace std;

class Solution {
public:
    int numWays(int n) {
        long long a=1;
        long long b=1;
        for(int i=0;i<=n-2;i++){
            int tm= b;
            b=(a+b)%1000000007;
            a= tm;
        }
        return b%1000000007;
    }
};