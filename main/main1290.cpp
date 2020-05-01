#include "../easy/1290ConvertBinaryNumberinaLinkedListtoInteger.cpp"

int main() {
    Solution def;
    ListNode *a1 = new ListNode(1);
    ListNode *a2 = new ListNode(0);
    ListNode *a3 = new ListNode(1);
    a1->next = a2;
    a2->next = a3;
    cout << def.getDecimalValue(a1) << endl;
    return 0;
}