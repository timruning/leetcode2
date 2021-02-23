//
// Created by 宋峰 on 2021/2/23.
//
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int max_position(vector<int> positions)
    {
        int mx=INT_MIN;
        for(auto i:positions)
            mx=max(mx,i);
        return mx;
    }

    bool isPossible(int d,vector<int> positions,int m)
    {
        int prev=positions[0],temp=1;
        for(int i=1;i<positions.size();i++)
        {
            if(abs(positions[i]-prev)>=d)
            {
                temp++;
                prev=positions[i];
            }
            if(temp==m)
                return true;
        }
        return temp==m;

    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int l=1,r=position[position.size()-1];
        int ans=l;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(isPossible(mid,position,m))
            {
                ans=max(ans,mid);
                l=mid+1;
            }
            else
                r=mid-1;
        }
        return ans;
    }

    int maxDistance1(vector<int>& position, int m) {
        sort(position.begin(),position.end());

        int result = (position[position.size()-1]-position[0])/(m-1);
        if(result<1){
            return result;
        }
        while (result>0){
            int begin = position[0];
            int count =1;
            for(int i=1;i<position.size();i++){
                if(position[i]>= begin+result){
                    count+=1;
                    begin=position[i];
                }
            }
            if(count>=m){
                return result;
            }
            result--;
        }
        return result;
    }
};