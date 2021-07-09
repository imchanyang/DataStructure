#include <iostream>
#include <string>

using namespace std;

class arrQ {
private:
    int* Q;
    int rear;
    int front;
    int capacity;
    
public:
    arrQ(int cap) {
        this->capacity = cap+1;
        Q = new int[capacity];
        front = rear = 0;
        
        for (int i = 0; i < capacity; i++) {
            Q[i] = 0;
        }
    }
    
    bool isEmpty() {
        return front == rear;
    }
    
    bool isFull() {
        return front == (rear + 1) % capacity;
    }
    
    void enqueue(int dt) {
        if(isFull()) {
            cout << "FULL" << endl;
        }
        else {
            rear = rear + 1;
            Q[rear] = dt;
        }
    }
    
    void dequeue() {
        if(isEmpty()) {
            cout << "Empty" << endl;
        }
        else {
            front = front + 1;
            cout << Q[front] << endl;
            Q[front] = 0;
        }
    }
    
    int size() {
        return (rear - front + capacity) % capacity;
    }
    
    void _front() {
        if(isEmpty()) {
            cout << "Empty" << endl;
        }
        else {
            cout << Q[(front+1) % capacity] << endl;
        }
    }
    
    void _rear() {
        if(isEmpty()) {
            cout << "Empty" << endl;
        }
        else {
            cout << Q[rear] << endl;
        }
    }
   
};


int main() {
    
    int cap = 0;   // queue's capacity
    int M = 0;      // 명령어 수

    
    cin >> cap >> M;
    arrQ a(cap);
    string m; // 명령어
    
    for (int i = 0; i < M; i++) {
        cin >> m;
        
        if(m == "enqueue") {
            int dt;
            cin >> dt;
            a.enqueue(dt);
        }
        else if(m == "dequeue") {
            a.dequeue();
        }
        else if(m == "isEmpty") {
            cout << boolalpha << a.isEmpty() << endl;
        }
        else if(m == "size") {
            cout << a.size() << endl;
        }
        else if(m == "front") {
            a._front();
        }
        else if(m == "rear") {
            a._rear();
            
        }
        
    }
    
    
    return 0;
}
