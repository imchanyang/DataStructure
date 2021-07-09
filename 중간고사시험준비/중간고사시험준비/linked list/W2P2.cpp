//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class Node{
//private:
//    int data;
//    Node* pre;
//    Node* next;
//public:
//    Node(int dt) {
//        data = dt;
//        pre = NULL;
//        next = NULL;
//    }
//
//    friend class DoublyList;
//};
//
//class DoublyList {
//private:
//    Node* head;
//    Node* tail;
//    int n;
//public:
//    DoublyList() {
//        head = NULL;
//        tail = NULL;
//        n = 0;
//    }
//
//    bool empty() {
//        return ((head == NULL) && (tail == NULL));
//    }
//
//    void Print() {
//
//        if(empty()) {
//            cout << "empty" << endl;
//        }
//        else {
//            Node* curNode = head;
//            for(int i = 0; i < n; i++) {
//                if(i == n-1) {
//                    cout << curNode->data << endl;
//
//                    curNode = curNode->next;
//                }
//                else{
//                cout << curNode->data << " ";
//                curNode = curNode->next;
//
//            }
//            }
//        }
//    }
//
//    void Append(int dt) {
//        Node* newNode = new Node(dt);
//        if(empty()) {
//            head = newNode;
//            tail = newNode;
//            newNode->pre = head;
//            newNode->next = tail;
//            n++;
//        }
//        else {
//            tail->next = newNode;
//            newNode->pre = tail;
//            tail = newNode;
//            newNode->next = tail;
//
//            n++;
//        }
//        Print();
//    }
//
//    int Delete(int idx) {
//        int rdt;
//
//        if(empty() || (idx >= n)) {
//            rdt = -1;
//        }
//        else if(idx == 0) {
//            if(n == 1) {
//                Node* curNode = head;
//                head = NULL;
//                tail = NULL;
//                rdt = curNode->data;
//                delete curNode;
//
//            }
//            else {
//                Node* curNode = head;
//                head = curNode->next;
//                curNode->next->pre = head;
//                rdt = curNode->data;
//                delete curNode;
//            }
//            n--;
//        }
//        else if(idx == n-1){
//            Node* curNode = tail;
//            tail->pre->next = tail;
//            tail = tail->pre;
//            rdt = curNode->data;
//            delete curNode;
//            n--;
//        }
//        else{
//            Node* curNode = head;
//            for(int i = 0; i < idx; i++) {
//                curNode = curNode->next;
//            }
//            curNode->pre->next = curNode->next;
//            curNode->next->pre = curNode->pre;
//            rdt = curNode->data;
//            delete curNode;
//            n--;
//        }
//
//
//        cout << rdt << endl;
//        return rdt;
//    }
//
//    void Print_reverse() {
//
//        if(empty()) {
//            cout << "empty" << endl;
//        }
//        else {
//            Node* curNode = tail;
//        for(int i = 0; i < n; i++) {
//            if(i == n-1) {
//                cout << curNode->data << endl;
//                curNode = curNode->pre;
//            }
//            else{
//            cout << curNode->data << " ";
//            curNode = curNode->pre;
//            }
//        }
//
//        }
//    }
//
//    void Max() {
//        int max;
//
//        Node* cur_node;
//        cur_node = head;
//
//        if(empty()) {
//            cout << "empty" << endl;
//        }
//        else {
//            max = cur_node->data;
//            while(cur_node != tail) {
//                cur_node = cur_node->next;
//                if(max < cur_node->data) {
//                    max = cur_node->data;
//                }
//                
//            }
//            cout << max << endl;
//        }
//    }
//
//};
//int main() {
//    int T;
//    cin >> T;
//    DoublyList a;
//
//    while (T--) {
//        string M;
//        cin >> M ;
//
//        if(M == "Print") {
//            a.Print();
//        }
//        else if(M == "Append") {
//            int dt;
//            cin >> dt;
//            a.Append(dt);
//        }
//        else if(M == "Delete") {
//            int idx;
//            cin >> idx;
//            a.Delete(idx);
//        }
//        else if(M == "Print_reverse") {
//            a.Print_reverse();
//        }
//        else if(M == "Max") {
//            a.Max();
//        }
//    }
//    return 0;
//}
