//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class QueueArr {
//private:
//    int* Qarr;
//    int front;
//    int rear;
//    int capacity;
//    int n;
//    
//public:
//    QueueArr(int capa) {
//        capacity = capa + 1;
//        Qarr = new int[capacity];
//        for(int i = 0; i < capacity; i++) {
//            Qarr[i] = 0;
//        }
//        front = rear = 0;
//    }
//    
//    bool isEmpty() {
//        return (front == rear);
//    }
//    
//    bool isFull() {
//        return (front == (rear+1) % capacity);
//    }
//    
//    void enqueue(int dt) {
//        if(isFull()) {
//            cout << "FULL" << endl;
//        }
//        else {
//            rear = (rear + 1) % capacity;
//            Qarr[rear] = dt;
//            n++;
//        }
//    }
//    
//    void dequeue() {
//        if(isEmpty()) {
//            cout << "Empty" << endl;
//        }
//        else {
//            front = (front + 1) % capacity ;
//            cout << Qarr[front] << endl;
//            Qarr[front] = 0;
//            n--;
//        }
//    }
//    
//    void size() {
//        cout << n << endl;
//    }
//    
//    void Front() {
//        if(isEmpty()) {
//            cout << "Empty" << endl;
//        }
//        else {
//            cout << Qarr[(front+1)%capacity] << endl;
//        }
//    }
//    
//    void Rear() {
//        if(isEmpty()) {
//            cout << "Empty" << endl;
//        }
//        else {
//            cout << Qarr[rear] << endl;
//        }
//    }
//};
//
//int main() {
//    int capa, T;
//    
//    cin >> capa >> T;
//    
//    QueueArr a(capa);
//    
//    for(int i = 0; i < T; i++) {
//        string M;
//        cin >> M;
//        
//        if(M == "enqueue") {
//            int dt;
//            cin >> dt;
//            
//            a.enqueue(dt);
//        }
//        else if(M == "dequeue") {
//            a.dequeue();
//        }
//        else if(M == "isEmpty") {
//            cout << boolalpha << a.isEmpty() << endl;
//        }
//        else if(M == "size") {
//            a.size();
//        }
//        else if(M == "front") {
//            a.Front();
//        }
//        else if(M == "rear") {
//            a.Rear();
//        }
//    }
//    
//    return 0;
//}
