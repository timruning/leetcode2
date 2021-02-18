#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    vector<vector<string>> split(string s,int num){
        vector<vector<string>> result;
        if(num==1 && ((stoi(s)>0 && stoi(s)<=255 && !s[0]=='0') || s=="0" ) ){
            vector<string> x ;
            x.push_back(s);
            result.push_back(x);
            return result;
        }
        for(int i=1;i<=3;i++){
            string head = s.substr(0,i);
            if((stoi(s)>0 && stoi(s)<=255 && !s[0]=='0') || s=="0" ){
                vector<vector<string>> tmp = split(s.substr(i,s.size()),num-1);
                for(int j=0;j<tmp.size();j++){
                    if(tmp[j].size()==num-1){
                        tmp[j].insert(head,tmp[j].begin());
                        result.push_back(tmp[j]);
                    }
                }
            }
        }
        return result;
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> result = split(s,4);
    }
};