#include <iostream>
#include <string>
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
    
    void top() {
        if(isEmpty()) {
            cout << -1 << endl;
        }
        else {
            cout << v[root_index] << endl;
        }
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
            if(i == heap_size-1) {
                cout << v[i+1] << endl;
            }
            else {
                cout << v[i+1] << " ";
            }
            
        }
    }
};

int main() {
    
    int T;
    cin >> T;
    
    Heap a(MIN);
    
    while (T--)  {
        string M;
        cin >> M;
        
        if(M == "insert") {
            int dt;
            cin >> dt;
            a.insert(dt);
            
        }
        else if( M == "size") {
            cout <<  a.size() << endl;
        }
        else if(M == "isEmpty") {
            cout << a.isEmpty() << endl;
        }
        else if( M == "pop") {
            cout << a.pop() << endl;;
        }
        else if(M == "top") {
            a.top();
        }
        else if(M == "print") {
            a.print();
        }
    }
    
    return 0;
}
