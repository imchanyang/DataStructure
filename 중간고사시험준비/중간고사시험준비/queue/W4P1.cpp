//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class Node{
//private:
//    int data;
//    Node* next;
//public:
//    Node(int dt) {
//        data = dt;
//        next = NULL;
//    }
//    friend class QueueList;
//};
//
//class QueueList{
//private:
//    Node* head;
//    Node* tail;
//    int n;
//public:
//    QueueList() {
//        head = NULL;
//        tail = NULL;
//        n = 0;
//    }
//
//    bool isEmpty() {
//        return (head == NULL && tail == NULL);
//    }
//
//    void enqueue(int dt) {
//        Node* newNode = new Node(dt);
//        if(isEmpty()) {
//            head = newNode;
//            tail = newNode;
//            n++;
//        }
//        else {
//            tail->next = newNode;
//            tail = newNode;
//            n++;
//        }
//    }
//
//    void dequeue() {
//        Node* curNode = head;
//        if(isEmpty()) {
//            cout << "Empty" << endl;
//        }
//        else if(head == tail) {
//            head = NULL;
//            tail = NULL;
//            cout << curNode->data << endl;
//            delete curNode;
//            n--;
//        }
//        else {
//            head = curNode->next;
//            cout << curNode->data << endl;
//            delete curNode;
//            n--;
//        }
//        
//    }
//
//    void size() {
//        cout << n << endl;
//    }
//    void front() {
//        if(isEmpty()) {
//            cout << "Empty" << endl;
//        }
//        else {
//            cout << head->data << endl;
//        }
//    }
//
//    void rear() {
//        if(isEmpty()) {
//            cout << "Empty" << endl;
//        }
//        else {
//            cout << tail->data << endl;
//        }
//    }
//};
//
//int main() {
//    int T;
//    cin >> T;
//
//    QueueList a;
//    while (T--)
//    {
//        string M;
//        cin >> M;
//
//        if(M == "enqueue"){
//            int dt;
//            cin >> dt;
//            a.enqueue(dt);
//        }
//        else if(M == "dequeue") {
//            a.dequeue();
//        }
//        else if(M == "isEmpty") {
//           cout << boolalpha << a.isEmpty() << endl;
//        }
//        else if(M == "size") {
//            a.size();
//        }
//        else if(M == "front") {
//            a.front();
//        }
//        else if(M == "rear") {
//            a.rear();
//        }
//    }
//    
//    return 0;
//}
