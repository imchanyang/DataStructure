#include <iostream>
#include <vector>

using namespace std;

class PQ {
private:
    vector<int> v;
public:
    
    bool empty() {
        return v.size() == 0;
    }
    
    void print() {
        for(auto iter = --v.end(); iter != v.begin(); iter--) {
            cout << *iter << " ";
        }
        cout << *v.begin() <<  endl;
    }
    
    void insert(int dt) {
        vector<int>::iterator p = v.begin();
        
        if(empty()) {
            v.insert(p,dt);
        }
        else {
           while(p != v.end()) {
                if(*p > dt) {
                    v.insert(p, dt);
                    return;
                }
               p++;
            }
            v.insert(p, dt);
        }
    }
    
    
};

int main() {
    
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        
        PQ a;
        for(int i = 0; i < N; i++) {
            int dt;
            cin >> dt;
            a.insert(dt);
        }
        
        a.print();
    }
    return 0;
}
