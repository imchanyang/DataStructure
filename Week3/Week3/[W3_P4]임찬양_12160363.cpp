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
    int pop();
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

int LinkedStack::pop() {
    Node* cur_node = tp;
    if(empty()) {
        return -1;
    }
    else {
        tp = tp->next;
        n--;
        return  cur_node->data;
        
        
    }
}

int main() {
    
    LinkedStack a;
    
    string M; // 명령어
    int m; // 입력받을 명령어의 수
    int L = 0; // 명령어 제한을 위한 수
    
    cin >> m;
    
    while (L < m) {
        cin >> M ;
        
        for(int i = 0; i < M.length(); ++i) {
            
            
            
            if(M.at(i) == '-') {
                int A = a.pop();
                int B = a.pop();
                a.push(B - A);
            }
            else if(M.at(i) == '+') {
                int A = a.pop();
                int B = a.pop();
                a.push(B + A);
            }
            else if(M.at(i) == '*') {
                int A = a.pop();
                int B = a.pop();
                a.push(B * A);
            }
            else {
                int dt = M.at(i) - '0';
                a.push(dt);
            }
                        
            
            
        }
        cout << a.pop() << endl;
        L++;
    }
    
    return 0;
}
