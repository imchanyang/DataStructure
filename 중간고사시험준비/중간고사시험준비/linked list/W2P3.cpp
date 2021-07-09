//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class Node{
//private:
//    int data;
//    Node* next;
//public:
//    Node(int dt) {
//        data = dt;
//        next = NULL;
//    }
//    
//    friend class SinglyList;
//};
//
//class SinglyList{
//private:
//    Node* head;
//    Node* tail;
//    int n;
//public:
//    SinglyList() {
//        head = NULL;
//        tail = NULL;
//        n = 0;
//    }
//    
//    bool empty() {
//        return (head == NULL && tail == NULL);
//    }
//    
//    void Print() {
//        if(empty()) {
//            cout << "empty" << endl;
//        }
//        else {
//            Node* curNode = head;
//            while(curNode != NULL) {
//                if(curNode->next == NULL) {
//                    cout << curNode->data << endl;
//                    curNode = curNode->next;
//                    return;
//                }
//                cout << curNode->data << " ";
//                curNode = curNode->next;
//            }
//            }
//    }
//    
//    void Append(int dt) {
//        Node* newNode = new Node(dt);
//        if(empty()) {
//            head = newNode;
//            tail = newNode;
//        }
//        else {
//            tail->next = newNode;
//            tail = newNode;
//        }
//        n++;
//        Print();
//    }
//    
//    int Delete(int idx) {
//        Node* curNode = head;
//        int rdt;
//        if(empty() || (idx >= n)) {
//            rdt = -1;
//        }
//        else if(idx == 0) {
//            if(n ==  1) {
//                head = NULL;
//                tail = NULL;
//                rdt = curNode->data;
//                delete curNode;
//            }
//            else{
//                head = curNode->next;
//                rdt = curNode->data;
//                delete curNode;
//            }
//            
//            n--;
//        }
//        else if(idx == (n-1) ){
//            while(curNode->next != tail) {
//                curNode = curNode->next;
//            }
//            Node* curNode2 = tail;
//            tail = curNode;
//            curNode->next = NULL;
//            rdt = curNode2->data;
//            delete curNode2;
//            n--;
//            
//        }
//        else {
//            for(int i =0 ; i < idx-1; i++)  {
//                curNode = curNode->next;
//            }
//            Node* delNode = curNode->next;
//            rdt = delNode->data;
//            curNode->next = delNode->next;
//            delete delNode;
//            n--;
//                
//        }
//        
//        cout << rdt << endl;
//        return rdt;
//    }
//    
//    void Insert(int idx, int dt) {
//        Node* newNode = new Node(dt);
//        Node* curNode = head;
//        if(idx > n) {
//            cout << "Index Error" << endl;
//        }
//        else if(empty()){
//            Append(dt);
//        }
//        else if(idx == n) {
//            Append(dt);
//        }
//        else if(idx == 0){
//            newNode->next = curNode;
//            head = newNode;
//            n++;
//            Print();
//        }
//        else {
//            for(int i = 0; i < idx -1; i++) {
//                curNode = curNode->next;
//            }
//            Node* idxNode = curNode->next;
//            curNode->next = newNode;
//            newNode->next = idxNode;
//            n++;
//            Print();
//        }
//    }
//    
//    void Min() {
//        Node* curNode = head;
//        int min ;
//        if(empty()) {
//            cout << "empty" << endl;
//            
//        }
//        else {
//            min = curNode->data;
//        while(curNode != tail) {
//            curNode = curNode->next;
//            if(min > curNode->data) {
//                min = curNode->data;
//            }
//        }
//        cout << min << endl;
//        }
//        }
//};
//
//
//int main() {
//    SinglyList a;
//    int T;
//    cin >> T;
//
//
//    while(T--) {
//        string M;
//        cin >> M;
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
//        else if(M == "Insert") {
//            int idx, dt;
//            cin >> idx >> dt;
//            a.Insert(idx, dt);
//        }
//        else if(M == "Min") {
//            a.Min();
//        }
//    }
//    return 0;
//}
