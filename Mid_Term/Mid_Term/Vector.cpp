//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class aVector {
//private:
//    int capacity;
//    int n;
//    int* A;
//public:
//    aVector(int capa) {
//        capacity = capa;
//        A = new int[capacity];
//        n = 0;
//    }
//    int size() {
//        return n;
//    }
//    
//    bool empty() {
//        return (size() == 0);
//    }
//    
//    int& operator[](int i) {
//        return A[i];
//    }
//    
//    int at(int i) {
//        if(i < 0 || i >= n) {
//            return -1;
//        }
//        else {
//            return A[i];
//        }
//    }
//    
//    void erase(int i) {
//        for(int j = i+1; j < n; j++) {
//            A[j -1] = A[j];
//        }
//        A[capacity] = 0;
//        n--;
//    }
//    void reserve(int N) {
//        if(capacity >= N) {
//            return ;
//        }
//        else {
//            int* B = new int[N];
//            for(int i = 0; i < n; i++) {
//                B[i] = A[i];
//            }
//            if(A != NULL) {
//                delete[] A;
//            }
//            A = B;
//            capacity = N;
//        }
//        
//        
//    }
//    
//    void insert(int i, const int& dt) {
//        if(n >= capacity) {
//            reserve(max(1,2*capacity));
//        }
//            for(int j = n-1; j >= i; j--) {
//                A[j+1] = A[j];
//            }
//        A[i] = dt;
//        n++;
//        
//    }
//    
//    void Print() {
//        for(int i = 0; i < n; i++) {
//            cout << A[i] << " ";
//        }
//        cout << endl;
//    }
//};
//
//int main() {
//    
//    aVector a(5);
//    a.insert(0, 1);
//    a.insert(1, 2);
//    a.insert(2, 3);
//    a.insert(3, 4);
//    a.insert(4, 5);
//    
//    a.Print();
//    
//    a.insert(5,6);
//    a.Print();
//    cout << a[8]<< endl;
//    cout << a.at(8) << endl;
//    a.insert(6,7);
//    a.insert(6,8);
//    a.insert(6,9);
//    a.insert(6,10);
//    a.Print();
//    
//    a.insert(0,0);
//    a.Print();
//    return 0;
//}
