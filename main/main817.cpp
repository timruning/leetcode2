#include "../medium/817LinkedListComponents.cpp"
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
    vector<int> a = {1,2,0,4,3};
    ListNode *a1 = getList(a);
    printList(a1);
    vector<int> b = {3,4,0,2,1};

    int n = def.numComponents(a1,b);
    cout<<n<<endl;
    return 0;
}