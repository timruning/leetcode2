//
// Created by 宋峰 on 2018/9/20.
//
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=0;
        int fast=0;
        //寻找环相遇位置
        while (true){
            slow=nums[slow];
            fast=nums[nums[fast]];
            if(slow==fast){
                break;
            }
        }
        //寻找环与出发点相遇的节点
        /**
         * 带环链表的长度为a+c
         *  如果k步快慢指针相遇则
         *  fast: 2*k
         *  slow: k
         *  fast-slow: k=m*c
         *  slow: k=a+n*c+i
         *  => m*c=a+n*c+i
         *  => u*c=a+i
         *  所以从头开始的fast必然会与slow相遇。
         *  而且相遇点必然是环的起始点。
         * */
        int finder=0;
        while (true){
            finder=nums[finder];
            slow=nums[slow];
            if(finder==slow){
                break;
            }
        }
        return finder;
    }
};