#include "../medium/1171RemoveZeroSumConsecutiveNodesfromLinkedList.cpp"
#include "../common/common.cpp"

void printList(ListNode *head) {
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
    vector<int> x = {1,2,-3,3,1};
    ListNode *head = getList(x);
    printList(head);
    ListNode *head2 = def.removeZeroSumSublists(head);
    printList(head2);
    return 0;
}