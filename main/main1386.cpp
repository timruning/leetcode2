#include "../medium/1386CinemaSeatAllocation.cpp"

int main() {
    Solution def;
    int n = 3;
    vector<vector<int>> vec = {{1,2},{1,3},{1,8},{2,6},{3,1},{3,10}};
    cout<< def.maxNumberOfFamilies(n,vec) << endl;
    return 0;
}
