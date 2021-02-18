#include <iostream>
#include <vector>
#include "../algorithm/trapping-rain-water-ii407.cpp"
using namespace std;
int main() {
    Solution sol ;
    
    int a[5][11] = {{9,9,9,9,9,9,8,9,9,9,9},
    {9,0,0,0,0,0,1,0,0,0,9},
    {9,0,0,0,0,0,0,0,0,0,9},
    {9,0,0,0,0,0,0,0,0,0,9},
    {9,9,9,9,9,9,9,9,9,9,9}};
    vector< vector <int> > vec;
    for(int i=0;i<5;i++){
        vector<int> x(a[i]+0,a[i]+11);
        vec.push_back(x);
    }
    int x = sol.trapRainWater(vec);
   
    cout<< x << endl;
}