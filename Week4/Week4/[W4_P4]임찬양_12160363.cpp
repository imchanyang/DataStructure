#include <iostream>

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
            Q[front] = 0;
        }
    }

    int size() {
        return (rear - front + capacity) % capacity;
    }

    int _front() {
        if(isEmpty()) {
            return 0;
        }
        else {
            return Q[(front+1) % capacity];
        }
        
    }


    void hP(int hp) {
        Q[(front+1) % capacity] = Q[(front+1) % capacity] + hp;
    }

};




int main() {

    int M = 0 ;
    cin >> M ;
    
    for(int i = 0; i < M; i++) {
        int N = 0;
        cin >> N;
        
        arrQ a(N);
        arrQ b(N);
        
        for(int j = 0; j < N; j++) {
            int dt;
            cin >> dt;
            a.enqueue(dt);
        }
        for(int k = 0; k < N; k++) {
            int dt;
            cin >> dt;
            b.enqueue(dt);
        }
        
        //game 구현
        int a_score = 0;
        int b_score = 0;
        int hp = 0;
        
        for(int l = 0 ; l < N; l++) {
            
            if(a._front() > b._front()) {
                a_score++;
                hp = a._front() - b._front();
                a.dequeue();
                b.dequeue();
                b.hP(hp);
            }
            else if(a._front() < b._front()) {
                b_score++;
                hp = b._front() - a._front();
                a.dequeue();
                b.dequeue();
                a.hP(hp);
            }
            // 무승부
            else {
                a.dequeue();
                b.dequeue();
            }
        }
        
        if(a_score >= b_score) {
            cout << a_score << endl;
        }
        else {
            cout << b_score << endl;
        }
        
    }


    return 0;
}
