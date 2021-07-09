//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class Node {
//private:
//    int data;
//    int Rank;
//public:
//
//    friend class aVector;
//    friend class Iterator;
//};
//
//
//
//class aVector {
//private:
//    int capacity;
//    int n;
//    Node* A;
//    
//    int l;
//public:
//    Node* Iterator;
//    aVector(int capa) {
//        capacity = capa;
//        A = new Node[capacity];
//        n = 0;
//    }
//    
//    int size() {
//        return n;
//    }
//    
//    bool isEmpty() {
//        return (size() == 0);
//    }
//    
//    Node* begin() {
//        Iterator = &A[0];
//        l=0;
//        return Iterator;
//    }
//
//    Node* end() {
//        Iterator = &A[size()];
//        l= size();
//        return Iterator;
//    }
//    
//    int operator*(int idx) {
//        return (A[idx].data);
//    }
//    
//    Node* operator++() {
//        l++;
//        Iterator = &A[l];
//        return Iterator;
//    }
//    
//    Node* operator--() {
//        l--;
//        Iterator = &A[l];
//        return Iterator;
//    }
//    
//    void insert(int idx, int dt) {
//        Node* newNode = new Node;
//        newNode->data = dt;
//        newNode->Rank = idx;
//        for(int i = size() -1; i >= idx; i--) {
//            A[i].Rank++;
//            A[i+1] = A[i];
//            
//            
//        }
//        A[idx] = *newNode;
//        n++;
//    }
//    
//    void erase(int idx) {
//        Node* curNode = &A[idx];
//        for(int i = idx+1; i < size(); i++) {
//            A[i].Rank--;
//            A[i-1] = A[i];
//            
//        }
//        delete curNode;
//        n--;
//    }
//    
//    void print() {
//    
//        for(Node* Iter = begin(); Iter != end(); Iter++) {
//            cout << Iter->Rank << " " << Iter->data << endl;
//
//        }
//
//        cout << endl;
//    }
//        
//        int atIndex(int idx) {
//            
//            cout << A[idx].data << endl;
//            return A[idx].data;
//        }
//
//        void indexOf() {
//            cout << Iterator->Rank << endl;
//        }
//};
//
//int main() {
//
//    aVector a(5);
//
//    a.insert(0, 1);
//    a.insert(1, 2);
//    a.insert(2, 3);
//    a.insert(3, 4);
//    
//    
//    a.begin();
//   
//    
//    a.print();
//    
//    a.insert(0,0
//             );
//    a.print();
//    
//    a.erase(0);
//    a.print();
//    
//    a.atIndex(2);
//    a.indexOf();
//    a.begin();
//    a.indexOf();
//    a.Iterator++;
//    a.indexOf();
//    
//    
//    return 0;
//}
