#include <iostream>

using namespace std;

class Node{
private:
    int data;
    Node* next;
public:
    Node(int dt) {
        data = dt;
        next = NULL;
    }
    friend class QueueList;
};

class QueueList{
private:
    Node* head;
    Node* tail;
    int n;
public:
    QueueList() {
        head = NULL;
        tail = NULL;
        n = 0;
    }

    bool isEmpty() {
        return (head == NULL && tail == NULL);
    }

    void enqueue(int dt) {
        Node* newNode = new Node(dt);
        if(isEmpty()) {
            head = newNode;
            tail = newNode;
            n++;
        }
        else {
            tail->next = newNode;
            tail = newNode;
            n++;
        }
    }

    int dequeue() {
        Node* curNode = head;


        if(head == tail) {
            int rem;
            head = NULL;
            tail = NULL;
            rem = curNode->data ;
            delete curNode;
            n--;
            return rem;
        }
        else {
            int rem;
            head = curNode->next;
            rem = curNode->data ;
            delete curNode;
            n--;
             return rem;
        }

    }

    void size() {
        cout << n << endl;
    }
    void front() {
        if(isEmpty()) {
            cout << "Empty" << endl;
        }
        else {
            cout << head->data << endl;
        }
    }

    void rear() {
        if(isEmpty()) {
            cout << "Empty" << endl;
        }
        else {
            cout << tail->data << endl;
        }
    }

    void Game(QueueList& b, int n) {
        int aWin = 0;
        int bWin = 0;
        int aHP = this->dequeue();
        int bHP = b.dequeue();
        int HP = 0;

        for(int i = 0; i < n; i++) {

            if(aHP < bHP ) {
                bWin++;
                HP = (bHP - aHP);
                if(i == n-1) {

                }
                else{
                aHP = this->dequeue();
                bHP = b.dequeue() + HP ;
                }
            }
            else if(aHP > bHP) {
                aWin++;
                HP = (aHP - bHP);
              
                aHP = this->dequeue() + HP ;
                bHP = b.dequeue();
                
            }
            else {
                 
              
                aHP = this->dequeue();
                bHP = b.dequeue();
            
            }

        }
        if(bWin < aWin) {
            cout << "1" << endl;
        }
        else if(bWin > aWin) {
            cout << "2" << endl;
        }
        else if(bWin == aWin) {
            cout << "0" << endl;
        }
    }
};

int main() {
    int T;
    cin >> T;


    while (T--)
    {
        QueueList a;
        QueueList b;
        int N;
        cin >> N;
        for(int i = 0; i < N; i++) {
           int dt;
           cin >> dt;
            a.enqueue(dt);
        }

         for(int j = 0; j < N; j++) {
           int dt;
           cin >> dt;
            b.enqueue(dt);
        }

        a.Game(b, N);

    }

    return 0;
}
 
