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
//    friend class QNod;
//};
//
//class QNod {
//private:
//    Node* front;
//    Node* rear;
//    int n;
//public:
//    QNod() {
//        n = 0;
//        front = rear = NULL;
//    }
//    
//    bool isEmpty() {
//        return (front == NULL && rear == NULL);
//    }
//    
//    void enqueue(int dt) {
//        Node* newNode = new Node;
//        newNode->data = dt;
//        
//        if(isEmpty()) {
//            front = newNode;
//            newNode->next = NULL;
//            rear = newNode;
//            n++;
//        }
//        else {
//            Node* curNode = rear;
//            curNode->next = newNode;
//            newNode->next = NULL;
//            rear = newNode;
//            n++;
//        }
//    }
//    int size() {
//        return n;
//    }
//    
//    void dequeue() {
//        if(isEmpty()) {
//            cout << "Empty" << endl;
//        }
//        else if(size() == 1) {
//            Node* curNode = front;
//            cout << curNode->data << endl;
//            front = rear = NULL;
//            delete curNode;
//            n--;
//            
//        }
//        else {
//            Node* curNode = front;
//            cout << curNode->data << endl;
//            front = curNode->next;
//            delete curNode;
//            n--;
//        }
//    }
//    
//    void Front() {
//        if(isEmpty()) {
//            cout << "Empty" << endl;
//        }
//        else {
//            cout << front->data << endl;
//        }
//    }
//    
//    void Rear() {
//        if(isEmpty()) {
//            cout << "Empty" << endl;
//        }
//        else {
//            cout << rear->data << endl;
//        }
//    }
//};
//int main() {
//    int capa, T;
//   
//       cin >> capa >> T;
//   
//       QNod a;
//   
//       for(int i = 0; i < T; i++) {
//           string M;
//           cin >> M;
//   
//           if(M == "enqueue") {
//               int dt;
//               cin >> dt;
//   
//               a.enqueue(dt);
//           }
//           else if(M == "dequeue") {
//               a.dequeue();
//           }
//           else if(M == "isEmpty") {
//               cout << boolalpha << a.isEmpty() << endl;
//           }
//           else if(M == "size") {
//               cout << a.size() << endl;
//           }
//           else if(M == "front") {
//               a.Front();
//           }
//           else if(M == "rear") {
//               a.Rear();
//           }
//       }
//       
//    return 0;
//}
