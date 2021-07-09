//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class QueueArr{
//private:
//    int* arr;
//    int capacity;
//    int f;
//    int r;
//public:
//    QueueArr(int capa) {
//        f = 0;
//        r = 0;
//        capacity = capa + 1;
//        arr = new int[capacity];
//    }
//
//    bool isEmpty() {
//        return (f == r);
//    }
//
//    int size() {
//        return ((r-f+capacity)%capacity);
//    }
//
//    void enqueue(int dt) {
//        if(size() == capacity-1) {
//            cout << "Full" << endl;
//        }
//        else{
//        r = (r+1) % capacity;
//        arr[r] = dt;
//        }
//    }
//    void dequeue() {
//        if(isEmpty()) {
//            cout << "Empty" << endl;
//        }
//        else{
//            f = (f + 1) % capacity;
//            cout << arr[f] << endl;
//
//        }
//    }
//
//    void front() {
//        if(isEmpty()) {
//            cout << "Empty" << endl;
//        }
//        else {
//        cout << arr[f+1] << endl;
//        }
//    }
//
//    void rear() {
//        if(isEmpty()) {
//            cout << "Empty" << endl;
//        }
//        else {
//            cout << arr[r] << endl;
//        }
//    }
//
//
//};
//int main() {
//    int N, T;
//    cin >> N >> T;
//
//    QueueArr a(N);
//
//    while(T--) {
//        string M;
//        cin >> M;
//
//        if(M == "enqueue") {
//            int dt;
//            cin >> dt;
//            a.enqueue(dt);
//        }
//        else if(M == "dequeue") {
//            a.dequeue();
//        }
//        else if(M == "isEmpty") {
//            cout << boolalpha << a.isEmpty() << endl;
//        }
//        else if(M == "size") {
//            cout << a.size() << endl;
//        }
//        else if(M == "front") {
//            a.front();
//        }
//        else if(M == "rear") {
//            a.rear();
//        }
//    }
//
//    return 0;
//}
