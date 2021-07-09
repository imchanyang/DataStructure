//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class StackArr{
//    private:
//    int* arr;
//    int capacity;
//    int t;
//
//    public:
//    StackArr(int capa) {
//        capacity = capa;
//        arr = new int[capacity];
//        t = -1;
//    }
//
//    bool empty() {
//        return (t == -1);
//    }
//
//    void top() {
//        if(empty()) {
//            cout << -1 << endl;
//        }
//        else{
//            cout << arr[t] << endl;
//        }
//    }
//
//    void push(int dt) {
//        if(t == (capacity-1)) {
//            cout << "FULL" << endl;
//        }
//        else {
//        t++;
//        arr[t] = dt;
//        }
//
//    }
//    void pop() {
//        if(empty()) {
//            cout << -1 << endl;
//        }
//        else {
//            cout << arr[t] << endl;
//            t--;
//        }
//    }
//
//
//};
//
//int main() {
//    int T ,N;
//    cin >> T >> N ;
//    StackArr a(T);
//   
//    while (N--)
//    {
//        string M;
//        cin >> M;
//
//        if(M == "empty") {
//            cout << a.empty() << endl;
//        }
//        else if(M == "top") {
//            a.top();
//        }
//        else if(M == "push") {
//            int dt;
//            cin >> dt;
//            a.push(dt);
//        }else if(M == "pop") {
//            a.pop();
//        }
//    }
//    
//
//    return 0;
//}
