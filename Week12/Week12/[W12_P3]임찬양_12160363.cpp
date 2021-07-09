#include <iostream>
#include <string>

#define NOITEM 0
#define ISITEM 1
#define AVAILABLE 2

using namespace std;


struct Entry {
    int key;
    string value;
    int valid;
    
    Entry() {
        key = 0;
        value = "";
        valid = NOITEM;
    }
    
    Entry(int key_, string value_) {
        key = key_;
        value = value_;
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
    
    int hash_func(int key) {
        return (key%capacity);
    }
    
    int hash_func2(int key) {
        return divisor - (key%divisor);
    }
    
    
public:
    HashTable(int N, int D) {
        capacity = N;
        divisor = D;
        hash_table = new Entry[capacity];
        return;
    }
    
    void put(int key, string value) {
        int idx = hash_func(key);
        int probing = 1;
        
        while(hash_table[idx].valid == ISITEM && probing <= capacity) {
            idx = hash_func(idx + hash_func2(key));
            probing++;
        }
        
        if(probing > capacity) return;
        
    
            hash_table[idx] = Entry(key, value);
            cout << probing << endl;
            return;
    }
    
    void erase(int key) {
        int idx = hash_func(key);
        int probing = 1;
        
        while(hash_table[idx].valid != NOITEM && probing <= capacity) {
            if(hash_table[idx].valid == ISITEM && hash_table[idx].key == key) {
                hash_table[idx].erase();
                return;
            }
            
            idx = hash_func(idx + hash_func2(key));
            probing++;
        }
        cout << "None" << endl;
        return;
    }
    
    string find(int key) {
        int idx = hash_func(key);
        int probing = 1;
        
        while(hash_table[idx].valid != NOITEM && probing <= capacity) {
            if((hash_table[idx].valid == ISITEM) && (hash_table[idx].key == key)) {
                return hash_table[idx].value;
            }
            idx = hash_func((idx + hash_func2(key)));
            probing++;
        }
        
        return "None";
    }
    
    
};



int main() {
    int T, N, D;
    cin >> T >> N >> D;
    HashTable a(N,D);
    
    while (T--) {
        string M;
        cin >> M;
        
        if(M == "put") {
            int dt; string va;
            cin >> dt;
            cin >> va;
            a.put(dt,va);
        }
        else if(M == "erase") {
            int dt;
            cin >> dt;
            a.erase(dt);
        }
        else if(M == "find") {
            int dt;
            cin >> dt;
            cout << a.find(dt) << endl;
        }
    }
    
    return 0;
}
