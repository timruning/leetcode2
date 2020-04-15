#include "../medium/1177CanMakePalindromefromSubstring.cpp"
#include "../common/common.h"
#include <istream>
using namespace std;
int main() {
    Solution def;
    string s = "hunu";
    vector<vector<int> > queries = {{2,3,1},{3,3,1},{0,3,0},{1,1,1},{2,3,0},{3,3,1},{0,3,1},{1,1,1}};
    for(auto v:queries){
        printVec(v);
    }
    vector<bool> result = def.canMakePaliQueries(s,queries);
    printVec(result);

    result = def.canMakePaliQueries2(s,queries);
    printVec(result);
    return 0;
}