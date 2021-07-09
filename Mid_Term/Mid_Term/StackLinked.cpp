//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class Node {
//private:
//    int data;
//    Node* next;
//public:
//
//    friend class Stack;
//};
//
//class Stack {
//private:
//    Node* tp;
//    Node* bm;
//    int size;
//public:
//    Stack() {
//        tp = NULL;
//        bm = NULL;
//        size = 0;
//    }
//
//    bool empty() {
//        if(size == 0) {
//
//            return 1;
//        }
//        else {
//
//            return 0;
//        }
//    }
//
//    void top() {
//        if(empty()) {
//            cout << -1 << endl;
//        }
//        else {
//            cout << tp->data << endl;
//        }
//    }
//
//    void push(int dt) {
//        Node* newNode = new Node;
//        newNode->data = dt;
//
//        if (empty()) {
//            bm = newNode;
//            tp = newNode;
//            newNode->next = NULL;
//            size++;
//        }
//        else {
//            newNode->next = tp;
//            tp = newNode;
//            size++;
//        }
//
//    }
//    
//    void pop() {
//        if(empty()) {
//            cout << -1 << ㅌendl;
//        }
//        else {
//            Node* curNode = tp;
//            tp = curNode->next;
//            cout << curNode->data << endl;
//            size --;
//            delete curNode;
//        }
//    }
//
//};
//
//int main() {
//
//    int N;
//    cin >> N ;
//
//    Stack a;
//
//    for (int i = 0; i < N; i++) {
//        string M;
//        cin >> M;
//
//        if(M == "empty") {
//
//            cout <<a.empty() << endl;
//        }
//        else if(M == "top") {
//            a.top();
//        }
//        else if(M == "push") {
//            int dt;
//            cin >> dt;
//            a.push(dt);
//        }
//        else if(M == "pop") {
//            a.pop();
//        }
//    }
//    return 0;
//}
