//#include <string>
//#include <iostream>
//
//using namespace std;
//
//class Node{
//private:
//    int data;
//    Node* next;
//    Node* pre;
//public:
//    Node(int dt) {
//        data = dt;
//        next = NULL;
//        pre = NULL;
//    }
//
//    friend class DoublyList;
//    friend class Iterator;
//};
//
//class Iterator{
//private:
//    Node* v;
//    
//public:
//    Iterator(Node* u) {
//        v = u;
//    }
//    
//    Iterator& operator++() {
//        v = v->next;
//        return *this;
//    }
//    Iterator& operator--() {
//        v = v->pre;
//        return *this;
//    }
//    int& operator*() {
//        return v->data;
//    }
//    bool operator==(const Iterator& p) const{
//        return (v == p.v);
//    }
//    bool operator!=(const Iterator& p) const {
//        return (v != p.v);
//    }
//    
//    friend class DoublyList;
//    
//    
//};
//
//class DoublyList {
//private:
//    Node* head;
//    Node* tail;
//public:
//    DoublyList() {
//        head = new Node(0);
//        tail = new Node(0);
////        head->pre = NULL;
////        tail->next = NULL;
//        head->next = tail;
//        tail->pre = head;
//    }
//    
//    Iterator begin() const {
//        return Iterator(head->next);
//    }
//    
//    Iterator end() const {
//        return (Iterator(tail));
//    }
//    
//    bool empty() const {
//        return (head->next == tail && tail->pre == head);
//    }
//    
//    void insert(const Iterator& p,const int& dt) {
//        Node* newNode = new Node(dt);
//        
//        p.v->pre->next = newNode;
//        newNode->pre = p.v->pre;
//        newNode->next = p.v;
//        p.v->pre = newNode;
//    }
//    
//    void erase(const Iterator& p) {
//        
//        
//        if(empty()) {
//            cout << "Empty" << endl;
//        }
//        else {
//            p.v->pre->next = p.v->next;
//            p.v->next->pre = p.v->pre;
//            delete p.v;
//        }
//        
//    }
//    void Print() {
//        if(empty()) {
//            cout << "Empty" << endl;
//        }
//        else {
//            Node* curNode = head;
//            while(curNode->next != tail) {
//                curNode = curNode->next;
//                cout << curNode->data << " ";
//            }
//            cout << endl;
//        }
//    }
//    
//        void find(int& dt) {
//            if(empty()) {
//                cout << "Empty" << endl;
//                return;
//            }
//            else {
//    
//                int idx=0;
//                for(Iterator q = begin(); q != end(); ++q) {
//                    if(q.v->data == dt) {
//                        cout << idx << endl;
//                        return;
//                    }
//                    idx++;
//                }
//            }
//            cout << -1 << endl;
//        }
//};
//
//int main() {
//    
//    int T;
//    cin >> T;
//    DoublyList a;
//    Iterator iter = a.begin();
//    
//    while (T--) {
//        string M;
//        cin >> M;
//        
//        if(M == "begin") {
//            iter = a.begin();
//        }
//        else if(M == "end") {
//            iter = a.end();
//        }
//        else if(M == "insert") {
//            int dt;
//            cin >> dt;
//            a.insert(iter, dt);
//        }
//        else if(M == "erase") {
//            a.erase(iter);
//        }
//        else if(M == "++") {
//            ++iter;
//        }
//        else if(M == "--") {
//            --iter;
//        }
//        else if(M == "print") {
//            a.Print();
//        }
//        else if(M == "find") {
//            int dt;
//            cin >> dt;
//            a.find(dt);
//        }
//    }
//
//    return 0;
//}
