#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* pre;
    
 
    
    friend class D_LinkedList;
};

class D_LinkedList {
private:
    Node* head;
    Node* tail;
    int size = 0;
    
public:
    D_LinkedList();
    int Empty();
    int List_Size();
    void Print();
    void Append(int dt);
    int Delete(int idx);
    void Print_reverse();
    void Sum();
};

D_LinkedList::D_LinkedList() {
 
    head = NULL;
    tail = NULL;

}

int D_LinkedList::Empty() {
    if(head == NULL && tail == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

int D_LinkedList::List_Size() {
    return this->size;
}

void D_LinkedList::Print() {
    Node* cur_node;
    cur_node = head;

    if(Empty()){
        cout << "empty";
    }
    else {
        for (int i = 0; i < List_Size(); i++)
        {
            
            cout << cur_node->data << " ";
            cur_node = cur_node->next;
            
        }
        
    }
    cout << endl;
}

void D_LinkedList::Append(int dt) {
    Node* new_node = new Node;
    new_node->data = dt;



    if(Empty()) {
        head = new_node;
        tail = new_node;
        new_node->pre = head;
        new_node->next = tail;
       
        
    }
    else {
        new_node->pre = tail;
        new_node->pre->next = new_node;
        new_node->next = tail;
        tail = new_node;
        
        
    }
    this->size++;
    Print();
}



int D_LinkedList::Delete(int idx) {
    Node* cur_node;
    cur_node = head;
    
    int removedt;
    
    if(Empty() || idx >= List_Size() )
    {
        removedt = -1;
    }
    else if(idx == 0) {
        if(List_Size() == 1) {
            removedt = cur_node->data;
            
            head = NULL;
            tail = NULL;
            this->size--;
            delete cur_node;
            
        }
        else {
            removedt = cur_node->data;
            
            head = cur_node->next;
            cur_node->next->pre = head;
            this->size--;
            delete cur_node;
        }
        
    }
        else if(idx == List_Size() - 1) {
            
            
            removedt = tail->data;
            tail = tail->pre;
            tail->pre->next = tail;
            
            this->size--;
            
            
    }
    else {
        Node* cur_node;
        cur_node = head;
        
        
        for(int i = 0; i < idx; i++) {
            cur_node = cur_node->next;
        }
        removedt = cur_node->data;
        
        cur_node->pre->next = cur_node->next;
        cur_node->next->pre = cur_node->pre;
        
        delete cur_node;
        this->size--;
    }
    
    cout << removedt << endl;
    return removedt;

}

void D_LinkedList::Print_reverse() {
    Node* cur_node;
    cur_node = tail;
    
    if(Empty()) {
        cout << "empty";
    }
    else {
        for(int i = 0; i < List_Size(); i++) {
            cout << cur_node->data << " ";
            cur_node = cur_node->pre;
        }
    }
    
    cout << endl;
}

void D_LinkedList::Sum() {
    int sum = 0;
    
    Node* cur_node;
    cur_node = head;
    
    if(Empty()) {
        cout << sum << endl;
    }
    else {
        sum = cur_node->data;
        while(cur_node != tail) {
            cur_node = cur_node->next;
            sum = sum + cur_node->data;
        }
        cout << sum << endl;
    }
}

int main() {
    
    D_LinkedList a;
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
    
            else if(m == "Print_reverse") {
                a.Print_reverse();
                L++;
            }
    
            else if(m == "Sum") {
                a.Sum();
                L++;
            }
    
        }
    return 0;
}
