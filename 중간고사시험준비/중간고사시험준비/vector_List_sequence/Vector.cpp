//#include <iostream>
//
//using namespace std;
//
//class Vector {
//private:
//    int* arr;
//    int capacity;
//    int n;
//public:
//    Vector(int capa) {
//        capacity = capa;
//        arr = new int[capacity];
//        n = 0;
//     
//    }
//    int size() {
//        return n;
//    }
//    
//    int capa() {
//        return capacity;
//    }
//    
//    bool empty() {
//        return  n==0;
//    }
//    
//    int& operator[](int i) {
//        return arr[i];
//    }
//    
//    int at(int i) {
//        if(i < 0 || i >= size()) {
//            return -1;
//        }
//        else{
//            return arr[i];
//        }
//    }
//    
//    void erase(int idx) {
//        if(empty()) {
//            cout << "Empty" <<endl;
//        }
//        else{
//            for(int i = idx; i < n; i++){
//                arr[i] = arr[i+1];
//            }
//            arr[n-1] = 0;
//            n--;
//        }
//    }
//    
//    
//    void reserve(int N) {
//        int* arr_ = new int[N];
//        for(int i =0; i < N; i++) {
//            arr_[i] = this->arr[i];
//        }
//        arr = arr_;
//        capacity = N;
//    }
//    
//    void insert(int idx ,int dt) {
//        if(size() == capacity) {
//            reserve(2*capacity);
//        }
//        for(int i = n-1 ; i >= idx; i-- ) {
//            arr[i+1] = arr[i];
//        }
//        arr[idx] = dt;
//        n++;
//    }
//    
//    void Print() {
//        for(int i = 0; i < n; i++) {
//            if(i == n-1) {
//                cout << arr[i]<< endl;
//            }
//            else {
//            cout << arr[i] << " " ;
//            }
//        }
//    }
//    
//    
//    
//};
//
//int main() {
//    
//    Vector a(5);
//    a.insert(0, 1);
//    a.insert(1, 2);
//    a.insert(2, 3);
//    a.Print();
//    a.insert(3, 4);
//    a.insert(4, 5);
//    a.Print();
//    cout << a.size() << endl;
//    cout << a.capa() << endl;
//    a.insert(0, 0);
//    a.Print();
//    cout << a.size() << endl;
//    cout << a.capa() << endl;
//    
//    cout << a[5] << endl;
//    cout << a.at(5) << endl;
//    
//    
//    
//    return 0;
//}
