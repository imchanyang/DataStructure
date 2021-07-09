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
//    
//    void Pool(int n) {
//        int a[n];
//        int i = -1;
//        int max;
//        
//        for(Iterator q = begin(); q != end(); ++q) {
//            max = q.v->pre->data;
//            if(max < q.v->data) {
//                max = q.v->data;
//            }
//            if(max < q.v->next->data) {
//                max = q.v->next->data;
//            }
//            i++;
//            a[i] = max;
//        }
//        
//        for(int j = 0; j < n; j++) {
//            if(j==n-1) {
//                cout << a[j] << endl;
//            }
//            else {
//            cout << a[j] << " " ;
//            }
//        }
//    }
//};
//
//int main() {
//
//    int T;
//    cin >> T;
//
//
//    while (T--) {
//        DoublyList a;
//        Iterator iter = a.begin();
//        int N;
//        cin >> N;
//        for(int i = 0; i < N; i++) {
//            int dt;
//            cin >> dt;
//            a.insert(iter, dt);
//        }
//        a.Pool(N);
//    }
//
//    return 0;
//}
