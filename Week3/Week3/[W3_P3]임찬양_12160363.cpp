#include <iostream>
#include <string>

using namespace std;

class Node {
private:
    int data;
    Node* next;
    
public:
    Node(int dt) {
        this->next = NULL;
        this->data = dt;
    }
    friend class LinkedStack;
};

class LinkedStack {
private:
    Node* tp;
    Node* bm;
    int n;
    
public:
    LinkedStack();
    int empty();
    int top();
    void push(int dt);
    void pop();
};

LinkedStack::LinkedStack() {
        this->tp = NULL;
        this->bm = NULL;
        this->n = 0;
}

int LinkedStack::empty() {
    if(n == 0) {
        
        return 1;
    }
    else {
        
        return 0;
    }
}

int LinkedStack::top() {
    if(empty()) {
        
        return -1;
    }
    else {
        return  tp->data;
    }
}

void LinkedStack::push(int dt) {
    Node* new_node = new Node(dt);
    
    if(empty()) {
        tp = new_node;
        bm = new_node;
        n++;
    }
    else {
        new_node->next = tp;
        tp = new_node;
        n++;
    }
}

void LinkedStack::pop() {
    Node* cur_node = tp;
    
    if(empty()) {
        cout << -1 << endl;
    }
    else {
        cout << tp->data << endl;
        tp = tp->next;
        n--;
        delete cur_node;
    }
}

int main() {
    
    LinkedStack a;
    
    int M; // 명령어 수
    int L = 0; // 명령어 만큼 작동하고 끝내기 위한 수
   
    string m; // 명령어
    
    cin >> M;
    
    while(L < M) {
        cin >> m;
        
        if(m == "empty") {
            cout << a.empty() << endl;
            L++;
        }
        else if(m == "top") {
            cout << a.top() << endl;
            L++;
        }
        else if(m == "push") {
            int dt;
            cin >> dt;
            
            a.push(dt);
            L++;
        }
        else if(m == "pop") {
            a.pop();
            L++;
        }
      
    }
    
    return 0;
}
