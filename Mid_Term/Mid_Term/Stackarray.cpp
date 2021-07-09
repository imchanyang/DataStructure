//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class Stackarr {
//private:
//    int t;
//    int* arr;
//    int capacity;
//public:
//    Stackarr(int capa) {
//        t = -1;
//        capacity = capa;
//        arr = new int[capacity];
//    }
//    
//    bool empty() {
//        if(t == -1) {
//            return 1;
//        }
//        else {
//            return  0;
//        }
//    }
//    
//    int size() {
//        return t+1;
//    }
//    
//    void top() {
//        if(empty()) {
//            cout << -1 << endl;
//        }
//        else {
//            cout << arr[t] << endl;
//        }
//    }
//    
//    void push(int dt) {
//        if(size() == capacity) {
//            cout << "FULL" << endl;
//        }
//        t++;
//        arr[t] = dt;
//    }
//    
//    void pop() {
//        if(empty()) {
//            cout << -1 << endl;
//        }
//        else {
//            
//            
//            cout << arr[t] << endl;
//            arr[t] = 0;
//            t--;
//            
//        }
//    }
//    
//};
//
//int main() {
//    
//        int N;
//        cin >> N ;
//        
//        
//        Stackarr a(10);
//    
//        for (int i = 0; i < N; i++) {
//            string M;
//            cin >> M;
//    
//            if(M == "empty") {
//    
//                cout <<a.empty() << endl;
//            }
//            else if(M == "top") {
//                a.top();
//            }
//            else if(M == "push") {
//                int dt;
//                cin >> dt;
//                a.push(dt);
//            }
//            else if(M == "pop") {
//                a.pop();
//            }
//        }
//    return 0;
//}
