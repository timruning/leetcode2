#include "../medium/707DesignLinkedList.cpp"

void printVec(const vector<string> &vec) {
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
}

int main() {
    MyLinkedList x;
//    x.addAtHead(1);
//    x.addAtTail(3);
//    x.addAtIndex(1, 2);
//    cout << x.get(1) << endl;
//    x.deleteAtIndex(1);
//    cout << x.get(1) << endl;

//    x.addAtHead(1);
//    x.deleteAtIndex(0);

//    x.addAtHead(2);
//    x.deleteAtIndex(1);
//    x.addAtHead(2);
//    x.addAtHead(7);
//    x.addAtHead(3);
//    x.addAtHead(2);
//    x.addAtHead(5);
//    x.addAtTail(5);
//    cout<<x.get(5)<<endl;
//    x.deleteAtIndex(6);
//    x.deleteAtIndex(4);

//    ["MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"]
//    [[],[1],[3],[1,2],[1],[1],[1]]

//    x.addAtHead(1);
//    x.addAtTail(3);
//    cout << x.get(0) << endl;
//    x.addAtIndex(1, 2);
//    cout << x.get(1) << endl;
//    x.deleteAtIndex(1);
//    cout << x.get(1) << endl;

//    ["MyLinkedList","addAtHead","get","addAtIndex","addAtIndex","deleteAtIndex","addAtHead","addAtHead","deleteAtIndex","addAtIndex","addAtHead","deleteAtIndex"]
//    [[],[9],[1],[1,1],[1,7],[1],[7],[4],[1],[1,4],[2],[5]]

    x.addAtHead(9);
    x.get(1);
    x.addAtIndex(1,1);
    x.addAtIndex(1,7);
    x.deleteAtIndex(1);
    x.addAtHead(7);
    x.addAtHead(4);
    x.deleteAtIndex(1);
    x.addAtIndex(1,4);
    x.addAtHead(2);
    x.deleteAtIndex(5);

    return 0;
}