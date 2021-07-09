#include <iostream>
#include <vector>

using namespace std;

enum direction {
    MIN = 1, MAX = -1
};

class Heap{
    
private:
    vector<int> v;
    int heap_size;
    int root_index;
    int direction;
    
public:
    Heap(int di) {
        v.push_back(-1);
        heap_size = 0;
        root_index = 1;
        direction = di;
    }
    
    void Swap(int idx1, int idx2) {
        v[0] = v[idx1];
        v[idx1] = v[idx2];
        v[idx2] = v[0];
    }
    
    void upHeap(int idx) {
        if(idx == root_index) {
            return;
        }
        else {
            int parent = idx/2;
            if((v[parent] * direction) > (v[idx] * direction)) {
                Swap(parent, idx);
                upHeap(parent);
            }
        }
    }
    
    void downHeap(int idx) {
        int left = idx * 2;
        int right = (idx * 2) + 1;
        
        if(right <= heap_size) {
            if(v[left] * direction <= v[right] * direction) {
                if(v[left] * direction < v[idx] * direction) {
                    Swap(left,idx);
                    downHeap(left);
                }
                else {
                    return;
                }
            }
            else {
                if(v[right] *direction < v[idx] *direction) {
                    Swap(right, idx);
                    downHeap(right);
                }
                else {
                    return;
                }
            }
        }
        else if(left <= heap_size) {
            if(v[left] * direction < v[idx] * direction) {
                Swap(left,idx);
                downHeap(left);
            }
            else {
                return;
            }
        }
        else {
            return;
        }
    }
    
    void insert(int dt) {
        v.push_back(dt);
        heap_size++;
        upHeap(heap_size);
       
    }
    
    int pop() {
        if(isEmpty()) {
            return -1;
        }
        int top = v[root_index];
        v[root_index] = v[heap_size] ;
        heap_size--;
        v.pop_back();
        downHeap(root_index);
        return top;
    }
    
    int top() {
      
            return  v[root_index] ;
        
    }
    
    bool isEmpty() {
        return heap_size == 0;
    }
    
    int size() {
        return heap_size;
    }
    
    void print() {
        if(isEmpty()) {
            cout << -1 << endl;
            
        }
        else {
            for(int i = 0; i < heap_size;i++)
            if(i == (heap_size-1)) {
                cout << v[i+1] << endl;
            }
            else {
                cout << v[i+1] << " ";
            }
            
        }
    }
    
    int FindMax() {
        int Max = 0;
        for(int i = 0; i < heap_size; i++) {
            if(Max < v[i+1]) {
                Max = v[i+1];
            }
        }
        return Max;
    }
    
    int FindMin() {
        int Min = v[1];
        for(int i = 0; i < heap_size; i++) {
            if(Min > v[i+1]) {
                Min = v[i+1];
            }
        }
        return Min;
    }
    

    
    void PS(int p) {
        int tmp = p;
        
        if(size() == 1) {
            return;
        }
        if(tmp > this->FindMin()) {
            int a = this->pop();
            int b = this->pop();
            int c = (a+b)/2;
            this->insert(c);
            PS(tmp);
        }
        else {
            return;
        }
    }
};

int main() {
    
    int T;
    cin >> T;
    

    while (T--)  {
        Heap a(MIN);
        int N, P;
        
        cin >> N >> P;
        
        for(int i = 0; i < N; i++) {
            int dt;
            cin >> dt;
            a.insert(dt);
        }


            a.PS(P);
        if(P > a.FindMin()) {
            cout << "False" << endl;
        }
        else {
            cout << "True" << endl;
            a.print();
        }
           
           
        
    }
    
    return 0;
}
