#include "../medium/148SortList.cpp"
#include "../common/common.cpp"

void printList(ListNode *head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

ListNode *getList(int *x, int n) {
    ListNode *head = new ListNode(x[0]);
    ListNode *p = head;
    for (int i = 1; i < n; i++) {
        ListNode *node = new ListNode(x[i]);
        p->next = node;
        p = node;
    }
    return head;
}

int main() {
    Solution def;
    int x[] = {-1,5,3,4,0};
    ListNode *head = getList(x, 5);
    printList(head);
    ListNode *head2 = def.sortList(head);
    printList(head2);
    return 0;
}