#include "../medium/143ReorderList.cpp"
#include "../common/common.cpp"

ListNode *getList(vector<int> vec) {
    ListNode *head = new ListNode(vec[0]);
    ListNode *p = head;
    for (int i = 1; i < vec.size(); i++) {
        ListNode *node = new ListNode(vec[i]);
        p->next = node;
        p = node;
    }
    return head;
}

void printList(ListNode *head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution def;
    ListNode *head = getList(vector<int>({1,2,3,4,5,6}));
    printList(head);
    def.reorderList(head);
    printList(head);
    return 0;
}