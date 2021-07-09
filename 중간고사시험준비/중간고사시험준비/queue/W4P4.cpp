//#include <iostream>
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
//    int dequeue() {
//
//
//            f = (f + 1) % capacity;
//            return arr[f];
//
//
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
//    void Game(QueueArr& b, int n) {
//        int aHP = this->dequeue();
//        int bHP = b.dequeue();
//        int HP = 0;
//
//        int aWin = 0;
//        int bWin = 0;
//
//        for(int i = 0; i < n ; i++) {
//            if(aHP > bHP) {
//                aWin++;
//                HP = aHP - bHP;
//                aHP = this->dequeue() ;
//                bHP = b.dequeue()+ HP;
//            }
//            else if(aHP < bHP) {
//                bWin++;
//                HP = bHP - aHP;
//                aHP = this->dequeue()+ HP ;
//                bHP = b.dequeue();
//            }
//            else {
//                aHP = this->dequeue() ;
//                bHP = b.dequeue();
//            }
//        }
//
//        if(aWin > bWin) {
//            cout << aWin << endl;
//        }
//        else if(aWin < bWin) {
//            cout << bWin << endl;
//        }
//        else {
//            cout << aWin << endl;
//        }
//    }
//
//
//};
//int main() {
//    int T;
//    cin >> T;
//
//
//
//    while(T--) {
//      int N;
//      cin >> N ;
//        QueueArr a(N);
//        QueueArr b(N);
//      for(int i = 0; i < N; i++) {
//          int dt;
//          cin >> dt;
//
//          a.enqueue(dt);
//      }
//      for(int j = 0; j < N; j++) {
//          int dt;
//          cin >> dt;
//
//          b.enqueue(dt);
//      }
//
//      a.Game(b,N);
//
//    }
//
//    return 0;
//}
