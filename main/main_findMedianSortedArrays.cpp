#include <vector>
#include "../algorithm/findMedianSortedArrays4.cpp"
using namespace std;
int main(int argc, char const *argv[])
{
    Solution sol;
    int a[]={1,2};
    vector<int> aa(a,a+2);
    int b[]={-1,3};
    vector<int> bb(b,b+2);
    double x = sol.findMedianSortedArrays(aa,bb);
    cout<<x<<endl;
    
    return 0;
}
