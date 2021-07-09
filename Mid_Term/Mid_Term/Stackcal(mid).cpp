//#include <iostream>
//#include <string>
//
//using namespace std;
//
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
//    int top() {
//        if(empty()) {
//            return -1;
//        }
//        else {
//            return tp->data;
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
//    int pop() {
//        if(empty()) {
//            return -1;
//        }
//        else {
//            Node* curNode = tp;
//            tp = curNode->next;
//          
//            size --;
//            return curNode->data;
//            
//        }
//    }
//    
//
//    
//  
//
//};
//
//int main() {
//
//   
//    int T;
//    cin >> T;
//    
//    for(int i = 0; i < T; i++) {
//        Stack a; // 수 저장 스택
//        Stack b; // 연산자 저장 스택
//        string M;
//        cin >> M;
//        for(int j = 0; j < M.size(); j++) {
//            switch (M[j]) {
//                case '+':
//                    b.push(M[j]);
//                    break;
//                case '-':
//                    b.push(M[j]);
//                    break;
//                case '*':
//                    b.push(M[j]);
//                    break;
//                default:
//                    a.push(M[j]-'0');
//                    break;
//            }
//        }
//   
//        cout << b.top() << endl;
//        cout << a.top() << endl;
//    }
//   
//    return 0;
//}
