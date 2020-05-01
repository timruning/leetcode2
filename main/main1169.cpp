#include "../medium/1169InvalidTransactions.cpp"
void printVec(const vector<string> &vec) {
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
}
int main() {
    Solution def;
    vector<string> a({"alice,20,800,mtv","alice,50,100,beijing"});
    vector<string> x = def.invalidTransactions(a);
    printVec(x);
    return 0;
}