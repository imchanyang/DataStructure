//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class arr {
//private:
//    int* arry;
//    int capacity;
//public:
//    arr(int sz) {
//        this->capacity = sz;
//        this->arry = new int[sz];
//        for(int i = 0; i < capacity; i++) {
//            arry[i] = 0;
//        }
//    }
//    void at(int idx);
//    void add(int idx, int dt);
//    void remove(int idx);
//    void set(int idx, int dt);
//    void print();
//    void find_max();
//};
//void arr::at(int idx) {
//    cout << arry[idx] << endl;
//}
//
//void arr::add(int idx, int dt) {
//    for(int i = capacity-2; i >= idx; i--) {
//        arry[i+1] = arry[i];
//    }
//    arry[idx] = dt;
//}
//
//void arr::remove(int idx) {
//    for(int i = idx; i < capacity; i++) {
//        arry[i] = arry[i+1];
//    }
//    arry[capacity-1] = 0;
//}
//
//void arr::set(int idx, int dt) {
//    arry[idx] = dt;
//    cout << arry[idx] << endl;
//}
//
//void arr::print() {
//    for(int i = 0; i < capacity; i++) {
//        if(i == capacity-1) {
//            cout << arry[i];
//        }
//        else{
//        cout << arry[i] << " ";
//        }
//    }
//    cout << endl;
//}
//
//void arr::find_max() {
//    int max = arry[0];
//    
//    for(int i = 1; i < capacity; i++) {
//        if(max < arry[i]) {
//            max = arry[i];
//        }
//    }
//    
//    cout << max << endl;
//}
//
//
//int main() {
//    int sz, T;
//    
//    cin >> sz >> T;
//    
//    arr a(sz);
//    
//    for(int i = 0; i < T; i++) {
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
