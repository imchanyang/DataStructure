//#include <iostream>
//#include <string>
//
//using namespace std;
//class arr {
//private:
//    int* arr_;
//    int capacity;
//    
//public:
//    arr(int capa) {
//        capacity = capa;
//        arr_ = new int[capacity];
//        for(int i = 0; i< capacity; i++) {
//            arr_[i] = 0;
//        }
//    }
//    
//    void at(int idx) {
//        cout << arr_[idx] << endl;
//    }
//    
//    void add(int idx, int dt) {
//        
//        for(int i = capacity-1; i > idx; i--) {
//            arr_[i] = arr_[i-1];
//        }
//        arr_[idx] = dt;
//    }
//    
//    void remove(int idx) {
//        for(int i = idx+1; i < capacity; i++) {
//            arr_[i-1] = arr_[i];
//        }
//        arr_[capacity-1] = 0;
//    }
//    
//    void set(int idx, int dt) {
//        arr_[idx] = dt;
//        cout << dt << endl;
//    }
//    
//    void print() {
//        for(int i = 0; i< capacity; i++) {
//            if(i == capacity-1) {
//                cout << arr_[i] << endl;
//                return ;
//            }
//            cout << arr_[i] << " ";
//        }
//    }
//    
//    void find_max() {
//        int max = 0;
//        for(int i = 0; i < capacity; i++) {
//            if(max < arr_[i]) {
//                max = arr_[i];
//            }
//        }
//        cout << max << endl;
//    }
//    
//    
//};
//
//
//
//int main() {
//    
//    int N, T;
//    cin >> N >> T;
//    
//    arr a(N);
//    
//    while(T--) {
//        string M;
//        cin >> M;
//        
//        if(M == "at") {
//            int idx;
//            cin >> idx;
//            a.at(idx);
//        }
//        else if(M == "add") {
//            int idx, dt;
//            cin >> idx >> dt;
//            a.add(idx, dt);
//        }
//        else if(M == "remove") {
//            int idx;
//            cin >> idx;
//            a.remove(idx);
//        }
//        else if(M == "set") {
//            int idx, dt;
//            cin >> idx >> dt;
//            a.set(idx, dt);
//        }
//        else if(M == "print") {
//            a.print();
//        }
//        else if(M == "find_max") {
//            a.find_max();
//        }
//    }
//    
//    return 0;
//}
