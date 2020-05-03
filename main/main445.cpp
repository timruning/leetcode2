#include "../medium/445AddTwoNumbersII.cpp"
#include "../common/common.cpp"

void printList(ListNode *head) {
    cout<<"a: ";
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

ListNode *getList(vector<int> x) {
    ListNode *head = new ListNode(x[0]);
    ListNode *p = head;
    for (int i = 1; i < x.size(); i++) {
        ListNode *node = new ListNode(x[i]);
        p->next = node;
        p = node;
    }
    return head;
}

int main() {
    Solution def;
    vector<int> a = {7 , 2 , 4 , 3};
    ListNode *a1 = getList(a);
    printList(a1);
    vector<int> b = {5 , 6 , 4};
    ListNode *b1 = getList(b);
    printList(b1);
    ListNode *c=def.addTwoNumbers(a1,b1);
    printList(c);
    return 0;
}