//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class Node {
//    private:
//    int data;
//    Node* next;
//    public:
//    Node(int dt) {
//        data = dt;
//        next = NULL;
//    }
//
//    friend class StackList;
//};
//
//
//class StackList {
//private:
//    
//    Node* head;
//    Node* tail;
//public:
//    StackList() {
//        
//        head = NULL;
//        tail = NULL;
//    }
//
//    bool empty() {
//        return (head == NULL && tail == NULL);
//    }
//
//    void top(){
//        if(empty()) {
//            cout << -1 << endl;
//        }
//        else {
//            
//            cout << tail->data << endl;
//        }
//    }
//
//    void push(int dt) {
//        Node* newNode = new Node(dt);
//
//        if(empty()) {
//           
//            head = newNode;
//            tail = newNode;
//        }
//        else {
//            
//            tail->next = newNode;
//            tail = newNode;
//        }
//    }
//
//    void pop() {
//        Node* curNode = head;
//        if(empty()) {
//            cout << -1 << endl;
//        }
//        else if(curNode == tail) {
//            head = NULL;
//            tail = NULL;
//            cout << curNode->data << endl;
//            delete curNode;
//        }
//        else{
//            
//            while(curNode->next != tail) {
//                curNode = curNode->next;
//            }
//            Node* delNode = tail;
//            tail = curNode;
//            curNode->next = NULL;
//            cout << delNode->data << endl;
//            delete delNode;
//        }
//    }
//
//};
//int main() {
//   int N;
//   cin >> N ;
//   StackList a;
//  
//   while (N--)
//   {
//       string M;
//       cin >> M;
//
//       if(M == "empty") {
//           cout << a.empty() << endl;
//       }
//       else if(M == "top") {
//           a.top();
//       }
//       else if(M == "push") {
//           int dt;
//           cin >> dt;
//           a.push(dt);
//       }else if(M == "pop") {
//           a.pop();
//       }
//   }
//   
//
//   return 0;
//}
