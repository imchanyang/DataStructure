#include <iostream>
#include <string>

#define NOITEM 0
#define ISITEM 1
#define AVAILABLE 2

using namespace std;


struct Entry {
    int key;
    
    int valid;
    
    Entry() {
        key = 0;
  
        valid = NOITEM;
    }
    
    Entry(int key_) {
        key = key_;
    
        valid = ISITEM;
    }
    
    void erase() {
        valid = AVAILABLE;
    }
};


class HashTable{
private:
    Entry* hash_table;
    int capacity;
    int divisor;
    int rem = 0;
    int capacity_b;
    int rem_b = 0;
    
    int hash_func(int key) {
        return (key%capacity);
    }
    
    int hash_func2(int key) {
        return divisor - (key%divisor);
    }
    
    
public:
   
    HashTable(int N, int re) {
        capacity = N;
   
        hash_table = new Entry[capacity];
        capacity_b = re;
        return;
    }
    
    void put(int key) {
        int idx =  (hash_func(key) + rem)%capacity;
        rem = idx;
        int probing = 1;
        
        rem_b = (rem_b - (key%capacity_b) + capacity_b)%capacity_b;

        
        while(hash_table[idx].valid == ISITEM && probing <= capacity) {
           
            probing++;
            if(probing == 2) {
                idx = (idx -((rem_b+1)%capacity)+capacity)%capacity;
                rem_b = (rem_b+1%capacity_b + rem_b)%capacity_b;
                rem = idx;                                
            }
            else {
              idx =   (hash_func(1) + rem)%capacity;

            rem = idx;
                rem_b = (rem_b - (1%capacity_b) + capacity_b)%capacity_b;
            }

        }
        
        if(probing > capacity) return;
        
    
            hash_table[idx] = Entry(key);
        cout << idx+1 ;
            return;
    }
    

    

};



int main() {
    int T;
    cin >> T ;
  
    
    while (T--) {
        int N1, N2, B;
      
        cin >> N1 >> N2 >> B;
        HashTable a(N1,N2);
        
        while (B--) {
            int d;
            cin >> d;

           
            a.put(d);
            if(B == 0) {
                
            }
            else {
            cout << " ";
            }
            
        }
        cout << endl;
        
    }
    
    return 0;
}
