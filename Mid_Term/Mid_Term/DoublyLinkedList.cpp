//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class Node {
//private:
//    int data;
//    Node* prev;
//    Node* next;
//public:
//    
//    
//    friend class D_List;
//};
//
//class D_List {
//private:
//    Node* head;
//    Node* tail;
//    int size = 0;
//    
//public:
//    D_List();
//    bool Empty();
//    void Print();
//    void Append(int& dt);
//    int Delete(int& idx);
//    void Print_reverse();
//    void Sum();
//};
//
//D_List::D_List() {
//    head = NULL;
//    tail = NULL;
//}
//
//bool D_List::Empty() {
//    return ((head == NULL) && (tail == NULL));
//}
//
//void D_List::Print() {
//    if(Empty()) {
//        cout << "empty" << endl;
//    }
//    else {
//        Node* curNode = head;
//        for(int i = 0; i < size; i++) {
//            
//            cout << curNode->data << " ";
//            curNode = curNode->next;
//        }
//        cout << endl;
//    }
//}
//
//void D_List::Append(int& dt) {
//    Node* newNode = new Node;
//    newNode->data = dt;
//    
//   
//    if(Empty()) {
//        head = newNode;
//        tail = newNode;
//        newNode->prev = head;
//        newNode->next = tail;
//    }
//    else {
//    
//        
//        newNode->prev = tail;
//        tail->next = newNode;
//        newNode->next = tail;
//        tail = newNode;
//    }
//    size++;
//    this->Print();
//}
//
//int D_List::Delete(int& idx) {
//    int removedt = 0;
//    Node* curNode = head;
//    if(Empty() || (idx >= size)) {
//        removedt = -1;
//    }
//    else if(idx ==0) {
//        if(size == 1) {
//            removedt = curNode->data;
//            head = NULL;
//            tail = NULL;
//            delete curNode;
//        }
//        else {
//            removedt = curNode->data;
//            head = curNode->next;
//            curNode->next->prev = head;
//            delete curNode;
//        }
//        size--;
//    }
//    else if(idx == size -1) {
//        curNode = tail;
//        removedt = curNode->data;
//        tail = curNode->prev;
//        curNode->prev->next = tail;
//        delete curNode;
//        size--;
//    }
//    else {
//        for(int i = 0; i < idx; i++) {
//            curNode = curNode->next;
//        }
//        removedt = curNode->data;
//        curNode->prev->next = curNode->next;
//        curNode->next->prev = curNode->prev;
//        
//        delete curNode;
//        size--;
//    }
//    cout << removedt << endl;
//    return removedt;
//}
//
//void D_List::Print_reverse() {
//    Node* curNode = tail;
//    if(Empty()) {
//        cout << "empty" << endl;
//    }
//    else{
//    for(int i = 0; i < size; i++) {
//        cout << curNode->data << " ";
//        curNode = curNode->prev;
//    }
//        cout << endl;
//    }
//}
//
//void D_List::Sum() {
//    int sum = 0;
//    Node* curNode = head;
//    if(Empty()) {
//        sum = 0;
//    }
//    else {
//        for(int i = 0; i < size; i++) {
//            sum = sum + curNode->data;
//            curNode = curNode->next;
//        }
//    }
//    
//    cout << sum << endl;
//}
//
//int main() {
//    
//        int T;
//    
//        cin >> T;
//        D_List a;
//    
//        for(int i = 0; i < T; i++) {
//            string M;
//            cin >> M;
//    
//            if(M == "Print") {
//                a.Print();
//            }
//            else if(M == "Append") {
//                int dt;
//                cin >> dt;
//                a.Append(dt);
//            }
//            else if(M == "Delete") {
//                int idx;
//                cin >> idx;
//                a.Delete(idx);
//            }
//            else if(M == "Print_reverse") {
//                
//                a.Print_reverse();
//            }
//            else if(M == "Sum") {
//                a.Sum();
//            }
//        }
//    return 0;
//}
