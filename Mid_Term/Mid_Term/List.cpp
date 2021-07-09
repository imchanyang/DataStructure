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
//    
//public:
//    friend class LIST;
//    friend class Iterator;
//};
//
//class Iterator {
//private:
//    Node* v;
//public:
//    Iterator(Node* u) {
//        v = u;
//    }
//    int& operator*() {
//        return v->data;
//    }
//    bool operator==(const Iterator& p) const {
//        return v == p.v;
//    }
//    bool operator !=(const Iterator& p) const {
//        return v != p.v;
//    }
//    Iterator& operator++() {
//        v = v->next;
//        return *this;
//    }
//    Iterator& operator--() {
//        v = v->prev;
//        return *this;
//    }
//    
//    friend class LIST;
//};
//
//class LIST {
//private:
//    int n;
//    Node* head;
//    Node* tail;
//public:
//    LIST() {
//        n = 0;
//        head = new Node;
//        tail = new Node;
//        head->data = 0;
//        tail->data = 0;
//        head->next = tail;
//        tail->prev = head;
//    }
//    
//    int size() const {
//        return n;
//    }
//    
//    bool empty() const {
//        return (size() == 0);
//    }
//    
//    Iterator begin() const {
//        return (Iterator(head->next));
//    }
//    
//    Iterator end() const {
//        return (Iterator(tail));
//    }
//    
//    void insert(const Iterator& p, const int& dt) {
//        Node* new_node = new Node;
//        new_node->data = dt;
//        
//        p.v->prev->next = new_node;
//        new_node->prev = p.v->prev;
//        new_node->next = p.v;
//        p.v->prev = new_node;
//        n++;
//    }
//    
//    void erase(const Iterator& p) {
//        if(empty()) {
//            cout << "Empty" << endl;
//        }
//        else {
//            p.v->prev->next = p.v->next;
//            p.v->next->prev = p.v->prev;
//            delete p.v;
//            n--;
//        }
//    }
//    
//    void reversePrint() {
//        
//        Node* cur = tail;
//        if(empty()) {
//            cout << "Empty" << endl;
//        }
//        else {
//            for(int i = 0; i < size(); i++) {
//                cur = cur->prev;
//                cout << cur->data << " ";
//            }
//            cout << endl;
//        }
//    }
//    
//    void find(int& dt) {
//        if(empty()) {
//            cout << "Empty" << endl;
//            return;
//        }
//        else {
//            
//            int idx=0;
//            for(Iterator q = begin(); q != end(); ++q) {
//                if(q.v->data == dt) {
//                    cout << idx << endl;
//                    return;
//                }
//                idx++;
//            }
//        }
//        cout << -1 << endl;
//    }
//};
//
//
//int main() {
//    int T;
//    cin >> T;
//
//    LIST a;
//  Iterator iter = a.begin();
//
//    for (int i = 0; i < T; i++){
//        string M;
//        cin >> M;
//
//        if(M =="begin") {
//            iter = a.begin();
//        }
//        else if(M == "end") {
//           iter = a.end();
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
//          
//            ++iter;
//        }
//        else if(M == "--") {
//        
//            --iter;
//        }
//        else if(M == "reversePrint") {
//            a.reversePrint();
//        }
//        else if(M == "find") {
//            int dt;
//            cin >> dt;
//            a.find(dt);
//        }
//    }
//    return 0;
//}
