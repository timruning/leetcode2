//
// Created by timruning on 18-5-11.
//

#include "../import_iostream.h"

class NextPermutation {
public:
    void nextPermutation(vector<int> &nums) {
        int minRevers = nums.size() - 1;
        while (minRevers > 0) {
            int front = minRevers - 1;
            if (nums[front] >= nums[minRevers])
                minRevers -= 1;
            else{
                break;
            }
        }

        reverse(nums.begin()+minRevers,nums.end());

        if(minRevers==0)
            return;
        else{
            int a=nums[minRevers-1];
            for(int i=minRevers;i<nums.size();i++){
                if(nums[i]>a){
                    nums[minRevers-1]=nums[i];
                    nums[i]=a;
                    break;
                }
            }
            return;
        }
    }
};