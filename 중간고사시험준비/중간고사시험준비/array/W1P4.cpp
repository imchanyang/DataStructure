//
//#include <iostream>
//
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
//    void shift(int d) {
//        for(int i = 0; i < d/2; i++) {
//            int temp;
//            temp = arr_[i];
//            arr_[i] = arr_[d-1-i];
//            arr_[d-1-i] = temp;
//        }
//
//        for(int j = 0; j < (capacity-d)/2; j++) {
//            int temp;
//            temp = arr_[d+j];
//            arr_[d+j] = arr_[capacity-1-j];
//            arr_[capacity-1-j] = temp;
//        }
//        for(int k = 0; k < capacity/2; k++) {
//            int temp;
//            temp = arr_[k];
//            arr_[k] = arr_[capacity-1-k];
//            arr_[capacity-1-k] = temp;
//        }
//    }
//
//
//};
//
//
//
//int main() {
//
//    int T;
//    cin >> T;
//
//    while(T--) {
//        int N, D;
//        cin >> N >> D;
//        arr a(N);
//        for(int i = 0; i < N; i++) {
//            int dt;
//            cin >> dt;
//            a.add(i, dt);
//        }
//        a.shift(D);
//        a.print();
//    }
//
//    return 0;
//}
//// 12345
//// 12354
//// 32154
//// 45123
