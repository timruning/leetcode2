18. 4Sum2.cpp
    先是尝试递归方法从4-3-2-1逐步计算集合，发现超时。
    然后尝试两两计算放入map中，查找。通过。
    其中将vector转为string可以做工共函数用。

DivideTwoIntegers29.cpp
    通过[1,2,4,8,16,32,64,128...]数组查找，按位运算求商

NextPermutation.cpp
    查找排序中下一个较大值。将末尾最大逆序反转。找到nums[index-1]可以替换的位置即可

MaximumProductSubarray.cpp
    查找序列中最大的乘积。
    通过0将序列分割，分别计算。
    对于子序列，注意负数的个数，和首尾负数影响的乘积。
    如果有0将结果与0比较即可。
    比较简单的地方是都是int，所以绝对值必然会大。

LargestSumofAverages2.cpp fail
