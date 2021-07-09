#include <iostream>
#include <string>

using namespace std;

class Node {
private:
    int data;
    Node* next;
public:
    friend class S_List;
};

class S_List {
private:
    Node* head;
    Node* tail;
    int L_size;
public:
    S_List();
    bool empty();
    void Print();
    void Append(int dt);
    int Delete(int idx);
    void Insert(int idx, int dt);
    void Min();
    void Sum() {
        int sum = 0;
        if(empty()) {
            sum = 0;
        }
        else {
            Node* curNode = head;
            for(int i = 0; i < L_size; i++) {
                sum += curNode->data;
                curNode = curNode->next;
            }
        }
        cout << sum << endl;
    }

};

S_List::S_List() {
    head = NULL;
    tail = NULL;
}

bool S_List::empty() {
    return ((head == NULL) && (tail == NULL));
}

void S_List::Print() {
    Node* curNode;
    curNode = head;
    if(empty()) {
        cout << "empty" << endl;
    }
    for(int i = 0; i < L_size; i++) {
        if(curNode->next == tail) {
            cout << curNode->data << endl;
        }
        else {
        cout << curNode->data << " ";
        curNode = curNode->next;
            
        }
    }
}

void S_List::Append(int dt) {
    Node* newNode = new Node;
    newNode->data = dt;
    Node* curNode = head;
    
    if(empty()) {
        head = newNode;
        newNode->next = tail;
        
    }
    else {
        for(int i = 0; i < L_size-1; i++) {
            
            curNode = curNode->next;
        }
        curNode->next = newNode;
        newNode->next = tail;
    }
    
    L_size++;
    this->Print();
}

int S_List::Delete(int idx) {
    Node* curNode = head;
    Node* preNode =nullptr;
    int removedt = 0;
    if(empty() || (idx >= L_size)) {
        removedt = -1;
    }
    else if(idx == 0) {
        if(L_size == 1) {
            removedt = curNode->data;
            head = NULL;
            tail = NULL;
            delete curNode;
           
        }
        else{
        removedt = curNode->data;
        head = curNode->next;
            delete curNode;
            
        }
        L_size--;
    }
    else {
        for(int i = 0; i < idx; i++) {
            if(i == idx-1) {
                preNode = curNode;
                curNode = curNode->next;
            }
            else{
            curNode = curNode->next;
            }
        }
        removedt = curNode->data;
        preNode->next = curNode->next;
        delete curNode;
        L_size--;
    }

    cout << removedt << endl;
    return removedt;
}


void S_List::Insert(int idx, int dt) {
    Node* curNode = head;
    Node* preNode = nullptr;
    
    Node* newNode = new Node;
    newNode->data = dt;
    
    if(idx > L_size) {
        cout << "Index Error" << endl;
    }
    else if(empty()) {
        this->Append(dt);
    }
    else if(idx == 0) {
        newNode->next = curNode;
        head = newNode;
        L_size++;
    }
    else {
        for(int i = 0; i < idx; i++) {
            if(i == idx-1) {
                preNode = curNode;
                curNode = curNode->next;
            }
            else {
            curNode = curNode->next;
            }
            
        }
        preNode->next = newNode;
        newNode->next = curNode;
        L_size++;
    }
}

void S_List::Min() {
    
    if(empty()) {
        cout << "empty" << endl;
    }
    else {
        Node* curNode = head;
        int min = curNode->data;
        for(int i = 0; i < L_size-1; i++) {
            curNode = curNode->next;
            if(min > curNode->data) {
                min = curNode->data;
            }
        }
        cout << min << endl;
    }
}

int main() {
    int T;
    
    cin >> T;
    S_List a;
    
    for(int i = 0; i < T; i++) {
        string M;
        cin >> M;
        
        if(M == "Print") {
            a.Print();
        }
        else if(M == "Append") {
            int dt;
            cin >> dt;
            a.Append(dt);
        }
        else if(M == "Delete") {
            int idx;
            cin >> idx;
            a.Delete(idx);
        }
        else if(M == "Insert") {
            int idx, dt;
            cin >> idx >> dt;
            a.Insert(idx, dt);
        }
        else if(M == "Sum") {
            a.Sum();
        }
    }
    return 0;
}
