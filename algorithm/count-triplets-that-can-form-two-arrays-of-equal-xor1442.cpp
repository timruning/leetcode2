#include<unordered_map>
#include<vector>

using namespace std;
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int x=0;
        unordered_map<int,vector<int> > mem ;
        int result =0 ;
        vector<int> index1;
        index1.push_back(-1);
        pair<int,vector<int> > p1(0,index1);
        mem.insert(p1);
        for(int i=0;i<arr.size();i++){
            x = x^arr[i];
            if(mem.find(x) != mem.end()){
                vector<int> index = mem.find(x)->second;
                for(int j=0;j< index.size() ;j++){
                    result+=(i-index[j]-1);
                }
                mem.find(x)->second.push_back(i);
            }else{
                vector<int> index ;
                index.push_back(i);
                pair<int,vector<int> > p(x,index);
                mem.insert(p);
            }
        }
        return result;
    }
};