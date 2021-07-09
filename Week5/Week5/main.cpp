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
//    friend class SequenceList;
//    friend class Iterator;
//};
//
//
//
//
//
//
//
//
//
//class SequenceList {
//private:
//    int n;
//    Node* head;
//    Node* tail;
//    
//public:
//    class Iterator {
//    private:
//        Node* v;
//        
//        
//    public:
//        Iterator(Node* u) {
//            v = u;
//        }
//        int& operator*() {
//            
//            return v->data;
//        }
//        
//        bool operator==(const Iterator& p) const {
//            
//            return v == p.v;
//        }
//        
//        bool operator!=(const Iterator& p) const {
//            
//            return v != p.v;
//        }
//        
//        Iterator& operator++() {
//            v = v->next;
//            
//            return *this;
//        }
//        
//        Iterator& operator--() {
//           
//            v = v->prev;
//            
//            return *this;
//        }
//        
//        friend class SequenceList;
//    };
//    
//    SequenceList() {
//        n = 0;
//        head = new Node;
//        tail = new Node;
//        
//        head->next = tail;
//        tail->prev = head;
//    }
//    
//    Iterator begin() {
//        
//        return Iterator(head->next);
//    }
//    
//    Iterator end() {
//        
//        return Iterator(tail);
//    }
//    
//    bool empty() const {
//        
//        return (n == 0);
//    }
//    
//    void insert(Iterator& p, int& dt) {
//        
////        if(p == --begin()) {
////            return;
////        }
//        Node* new_node = new Node;
//        Node* cur_node = p.v;
//        Node* pre_node = cur_node->prev;
//        
//        new_node->data = dt;
//        new_node->next = cur_node;
//        new_node->prev = pre_node;
//        pre_node->next = new_node;
//        cur_node->prev = new_node;
//        
//        n++;
//    }
//    
//    void erase(Iterator& p) {
//        if(empty()) {
//            cout << "Empty" << endl;
//        }
//        else {
//        Node* v = p.v;
//        Node* w = v->next;
//        Node* u = v->prev;
//        
//        u->next = w;
//        w->prev = u;
//       
//        
//        delete v;
//       
//        n--;
//        }
//    }
//    
//    void reversePrint() {
//        if(empty()) {
//            cout << "Empty" << endl;
//        }
//        
//        else {
//        Iterator q = --end();
//        for (int i = 0; i < n; i++) {
//            if(i == (n-1)) {
//                cout << q.v->prev->data;
//            }
//            else {
//            cout << q.v->data << " ";
//                --q;
//            }
//            
//        }
//        cout << endl;
//        }
//        
//    }
//    
//    void find(int& dt) {
//        if(empty()) {
//            cout << "Empty" << endl;
//        }
//        
//        else {
//            Iterator q = begin();
//            int i = 0;
//            for(int idx = 0; idx < n; idx++) {
//                if(q.v->data == dt) {
//                    cout << idx << endl;
//                    i++;
//                    break;
//                }
//                q.v = q.v->next;
//            }
//            
//            if(i == 0) {
//                cout << -1 << endl;
//            }
//        }
//    }
//    
//    friend class Iterator;
//};
//
//
//
//
//
//
//int main() {
//    
//    int T;
//    cin >> T;
//    
//    SequenceList a;
//    SequenceList::Iterator iter = a.begin();
//    
//    for (int i = 0; i < T; i++){
//        string M;
//        cin >> M;
//        
//        if(M =="begin") {
//            a.begin();
//        }
//        else if(M == "end") {
//            a.end();
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
//            if(iter == a.end()){
//                continue;
//            }
//                
//            ++iter;
//        }
//        else if(M == "--") {
//            if(iter == a.begin()){
//                continue;
//            }
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
