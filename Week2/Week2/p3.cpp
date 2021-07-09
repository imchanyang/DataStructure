#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    friend class S_LinkedList;
};

class S_LinkedList {
private:
    Node* head;
    Node* tail;
public:
    S_LinkedList();
    int Empty();
    int List_size();
    void Print();
    void Append(int dt);
    int Delete(int idx);
    void Insert(int idx, int dt);
    void Min();
    void Sum() {
        int sum = 0;
        if(Empty()) {
            sum = 0;
        }
        else {
            Node* curNode = head;
            for(int i = 0; i < List_size(); i++) {
                sum += curNode->data;
                curNode = curNode->next;
            }
        }
        cout << sum << endl;
    }

};

S_LinkedList::S_LinkedList() {
    head = NULL;
    tail = NULL;
}

int S_LinkedList::Empty() {
    if(head == NULL && tail == NULL){
        return 1;
    }
    else {
        return 0;
    }
}

int S_LinkedList::List_size() {
    int list_size = 1;
    Node* cur_node;
    cur_node = head;
    
    if(Empty()) {
        return 0;
    }
    else {
        while (cur_node->next != tail) {
            list_size++;
            cur_node = cur_node->next;
        }
        return list_size;
    }
}

void S_LinkedList::Print() {
    Node* cur_node;
    cur_node = head;
    
    if(Empty()){
        cout << "empty" << endl;
    }
    else {
        while(cur_node != tail) {
            if(cur_node->next == tail) {
                cout << cur_node->data;
            }
            else {
            cout << cur_node->data << " ";
            
            }
            cur_node = cur_node->next;
        }
        cout << endl;
    }
    
}

void S_LinkedList::Append(int dt) {
    Node* new_node = new Node;
    new_node->data = dt;
    
    Node* cur_node;
    cur_node = head;
    
    if(Empty()) {
        head = new_node;
        new_node->next = tail;
    }
    else {
        while(cur_node->next != tail) {
            cur_node = cur_node->next;
        }
        cur_node->next = new_node;
        new_node->next = tail;
        
    }
    Print();
}

int S_LinkedList::Delete(int idx) {
    Node* cur_node;
    cur_node = head;
    Node* pre_node;
    pre_node = head;
    int removedt = 0;
    
    if(Empty() || idx >= List_size()) {
        removedt = -1;
        cout << removedt << endl;
        
    }
    else if(idx == 0) {
        if(List_size() == 1) {
            removedt = cur_node->data;
            head = NULL;
            tail = NULL;
            delete cur_node;
        }
        else {
            removedt = cur_node->data;
            head = cur_node->next;
            delete cur_node;
        }
        cout << removedt << endl;
        
    }
    else {
        for(int i = 0; i < idx; i++) {
            cur_node = cur_node->next;
            
        }
        for(int j = 0; j < idx-1; j++) {
            pre_node =pre_node->next;
            
        }
        
        pre_node->next = cur_node->next;
        removedt = cur_node->data;
        delete cur_node;
        cout << removedt << endl;
    }
    return removedt;
    
}

void S_LinkedList::Insert(int idx, int dt) {
    Node* cur_node;
    cur_node = head;
    Node* pre_node;
    pre_node = head;
    
    Node* new_node = new Node;
    new_node->data = dt;
    
    if( idx < 0 || idx > List_size()) {
        cout << "Index Error" << endl;
    }
    else if(idx == List_size()) {
        Append(dt);
    }
    else if(idx == 0) {
        if(Empty()) {
            Append(dt);
        }
        else {
            
            head = new_node;
            new_node->next = cur_node;
            
            Print();
        }
    }
    else {
        for(int i = 0; i < idx; i++){
            cur_node = cur_node->next;
        }
        for(int j = 0; j < idx-1; j++) {
            pre_node =pre_node->next;
        }
        pre_node->next = new_node;
        new_node->next = cur_node;
        Print();
    }
}

void S_LinkedList::Min(){
    Node* cur_node;
    cur_node = head;
    int min;

    
    if(Empty()) {
        cout << "empty" << endl;
    }
    else {
        min = cur_node->data;
        while(cur_node->next != tail) {
            cur_node = cur_node->next;
            if(min > cur_node->data){
                min = cur_node->data;
            }
        }
        cout << min << endl;
    }
}











int main()
{
    S_LinkedList a;
    string m; //명령어
    int M; // 명령어의 수
    int L = 0;
    cin >> M ;
    
    while(L < M) {
         
        cin >> m;
        
        if(m == "Print") {
            a.Print();
            L++;
        }
        
        else if(m == "Append") {
            int dt;
            cin >> dt;
            a.Append(dt);
            L++;
        }
        
        else if(m == "Delete") {
            int idx;
            cin >> idx;
            a.Delete(idx);
            L++;
        }
        
        else if(m =="Insert") {
            int idx, dt;
            cin >> idx >> dt;
            a.Insert(idx, dt);
            L++;
        }
        
        else if(m == "Min") {
            a.Min();
            L++;
        }
        
    }
    
    return 0;
}

