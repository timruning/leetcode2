//
// Created by timruning on 18-5-8.
//
#include "../import_iostream.h"

class DivideTwoIntegers29 {
public:
    static int findIndex(long dividend, long divisor) {
        int result = 0;
        if (dividend <= divisor)
            return result;
        while (result < 31) {
            result += 1;
            long divisor1 = divisor << result;
            if (divisor1 < 0 || divisor1 > dividend)
                return result - 1;
        }
        return result;
    }

    static long divide2(long dividend, long divisor) {
        int a[31] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072,
                     262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728,
                     268435456, 536870912, 1073741824};
        if (dividend == -2147483648 && divisor == -1)
            return 2147483647;
        long dividend1 = dividend > 0 ? dividend : -dividend;
        long divisor1 = divisor > 0 ? divisor : -divisor;

        int result = 0;
        if (dividend1 < divisor1) {

        } else {
            int index = findIndex(dividend1, divisor1);
            result += a[index];
            long dividend2 = dividend1 - (divisor1 << index);
            result += divide2(dividend2, divisor1);
        }
        if ((dividend >= 0 && divisor > 0) || (dividend <= 0 && divisor < 0))
            return result;
        else
            return -result;
    }

    static int divide(int dividend, int divisor) {
        return divide2(dividend, divisor);
    }

    static void printLog(int num) {
        int begin = 1;
        for (int i = 1; i < num; i++) {
            cout << begin << ",";
            begin *= 2;
        }
    }

    static void test() {
        int a = -2147483648;
        int b = -1;
        int x = DivideTwoIntegers29::divide(a, b);
        cout << x << endl;
    }

};