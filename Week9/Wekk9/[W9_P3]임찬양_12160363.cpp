#include <iostream>
#include <vector>

using namespace std;

class isLess {
private:
    
public:
    bool operator() (const int a, const int b) const {
        if (a < b) {
            return true;
        }
        else {
            return false;
        }
    }
};

class PQ{
private:
    vector<int> v;
public:
    
    int size() {
        return v.size();
    }
    
    bool empty() {
        return v.size() == 0;
    }
    
    void print() {
        for(auto iter = v.begin(); iter != v.end(); iter++){
            cout << *iter << ' ';
        }
        cout << endl;
    }
    
    void insert(int dt) {
        v.push_back(dt);
    }
    
    int removemin() {
        vector<int>::iterator p = v.begin();
        isLess C;
        
        int m_value = *v.begin();
        
        for(auto iter = v.begin(); iter != v.end(); iter++) {
            if(!C(m_value, *iter)) {
                m_value = *iter;
                p = iter;
            }
        }
        v.erase(p);
        return m_value;
    }
    
};

int main() {
    
    int T;
    cin >> T;
    
    while (T--) {
        PQ a;
        PQ a_;
        int N;
        cin >> N;
        
        for(int i = 0; i < N; i++) {
            int dt;
            cin >> dt;
            a.insert(dt);
        }
        
        for(int j = 0; j < N; j++) {
            a_.insert(a.removemin());
        }
        
        a_.print();
        
    }
    return 0;
}
