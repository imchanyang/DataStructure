//
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
//   
//    void set(int idx, int dt);
//    void print();
//    void shift(int D);
//   
//};
//
//void arr::set(int idx, int dt) {
//    arry[idx] = dt;
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
//void arr::shift(int D) {
//    for(int i = 0; i < D/2; i++) {
//        int temp;
//        temp = arry[i];
//        arry[i] = arry[D-i-1];
//        arry[D-i-1] = temp;
//    }
//    
//    for(int i = 0; i < (capacity - D)/2; i++) {
//        int temp;
//        temp = arry[i+D];
//        arry[i+D] = arry[capacity-1-i];
//        arry[capacity-1-i] = temp;
//    }
//    
//    for(int i = 0; i < capacity/2; i++) {
//        int temp;
//        temp = arry[i];
//        arry[i] = arry[capacity-1-i];
//        arry[capacity-1-i] = temp;
//    }
//    
//    this->print();
//}
//
//
//
//int main() {
//    int sz, T;
//    int D;
//    cin >> T;
//    
//    
//    
//    for(int j = 0; j < T; j++) {
//        cin >> sz >> D;
//        arr a(sz);
//    for(int i = 0; i < sz; i ++) {
//        int dt;
//        cin >> dt;
//        a.set(i, dt);
//        
//    }
//        a.shift(D);
//    }
//
//    return 0;
//}
