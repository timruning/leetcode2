#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    double get_k(vector<int>& nums1, vector<int>& nums2,int k){
        if(nums1.size()==0){
            return nums2[k];
        }
        if(nums2.size()==0){
            return nums1[k];
        }
        vector<int> a= nums1;
        vector<int> b= nums2;
        if(k==0){
            return a[0]<b[0]? a[0]:b[0];
        }
        int step = (k+1)/2;
        if(step > nums1.size()){
            step = nums1.size();
        }
        if(step > nums2.size()){
            step = nums2.size();
        }

        if(a[step-1] < b[step-1]){
            a= vector<int> (a.begin()+step,a.end());
        }else{
            b= vector<int>(b.begin()+step,b.end());
        }
        return get_k(a,b,k-step);
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int k = (nums1.size() + nums2.size())/2;
        int k2 = (nums1.size() + nums2.size() -1 )/2;
        
        int ak = get_k(nums1,nums2,k);
        int ak2 = get_k(nums1,nums2,k2);

        return (ak+ak2)/2.0;

    }
};