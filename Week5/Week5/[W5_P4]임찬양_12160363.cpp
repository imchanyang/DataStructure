//#include <iostream>
//
//using namespace std;
//
//class Node {
//private:
//    int data;
//    Node* pre;
//    Node* next;
//    
//public:
//    
//    friend class SequenceList;
//    friend class Iterator;
//};
//
//class Iterator {
//private:
//    Node* v;
//    Iterator(Node* u) {
//        v = u;
//    }
//public:
//    int& operator*(){
//        return v->data;
//    }
//    bool operator==(const Iterator& p) const{
//        return v == p.v;
//    }
//    bool operator!=(const Iterator& p) const{
//        return v != p.v;
//    }
//    Iterator& operator++() {
//        v = v->next;
//        return *this;
//    }
//    Iterator& operator--() {
//        v = v->pre;
//        return *this;
//    }
//    
//    friend class SequenceList;
//};
//
//class SequenceList {
//private:
//    int n;
//    Node* head;
//    Node* tail;
//public:
//    SequenceList() {
//        n = 0;
//        head = new Node;
//        tail = new Node;
//        head->data = 0;
//        tail->data = 0;
//        head->next = tail;
//        tail->pre = head;
//    }
//    int size() const {
//        return n;
//    }
//    bool empty() const {
//        return (n == 0);
//    }
//    Iterator begin() const {
//        return Iterator(head->next);
//    }
//    Iterator end() const {
//        return Iterator(tail);
//    }
//    void insert(const Iterator& p, const int& dt) {
//        Node* new_node = new Node;
//        new_node->data = dt;
//        
//        p.v->pre->next = new_node;
//        new_node->pre = p.v->pre;
//        p.v->pre = new_node;
//        new_node->next = p.v;
//        n++;
//    }
//  
//    void erase(const Iterator& p) {
//        if(empty()) {
//            cout << "Empty" << endl;
//        }
//        else {
//            p.v->pre->next = p.v->next;
//            p.v->next->pre = p.v->pre;
//            
//            delete p.v;
//            n--;
//        }
//    }
//
//    void reversePrint() {
//        Node* cur = tail;
//        if(empty()) {
//            cout << "Empty" << endl;
//        }
//        else {
//        for(int i = 0; i < size(); i++) {
//            cur = cur->pre;
//            int m = cur->data;
//            cout << m << " ";
//            
//        }
//            cout << endl;
//        }
//        
//    }
//     
//    
//        void find(int& dt) {
//            if(empty()) {
//                cout << "Empty" << endl;
//            }
//    
//            else {
//                Iterator q = begin();
//                int i = 0;
//                for(int idx = 0; idx < n; idx++) {
//                    if(q.v->data == dt) {
//                        cout << idx << endl;
//                        i++;
//                        break;
//                    }
//                    q.v = q.v->next;
//                }
//    
//                if(i == 0) {
//                    cout << -1 << endl;
//                }
//            }
//        }
//    
//    void conVolution( Iterator& p) {
//        
//
//        for (int i = 0; i < size(); i++) {
//            cout << (1 * p.v->pre->data) + (3 * p.v->data) + (1 * p.v->next->data) << " ";
//            ++p;
//        }
//        cout << endl;
//        
//       
//    }
//};
//
//int main() {
//
//    int T;
//    cin >> T;
//
//    
//
//    for (int i = 0; i < T; i++){
//        int m;
//        cin >> m;
//        
//        SequenceList a;
//        Iterator iter(a.begin());
//        
//        for(int j = 0; j < m; j++) {
//            int dt;
//            cin >> dt;
//            
//            a.insert(iter, dt);
//        }
//        iter = a.begin();
//        a.conVolution(iter);
//    }
//    return 0;
//}
