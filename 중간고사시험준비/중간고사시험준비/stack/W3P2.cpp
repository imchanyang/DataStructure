//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class Node {
//    private:
//    int data;
//    Node* next;
//    public:
//    Node(int dt) {
//        data = dt;
//        next = NULL;
//    }
//
//    friend class StackList;
//};
//
//
//class StackList {
//private:
//    
//    Node* head;
//    Node* tail;
//public:
//    StackList() {
//        
//        head = NULL;
//        tail = NULL;
//    }
//
//    bool empty() {
//        return (head == NULL && tail == NULL);
//    }
//
//    void top(){
//        if(empty()) {
//            cout << -1 << endl;
//        }
//        else {
//            
//            cout << tail->data << endl;
//        }
//    }
//
//    void push(int dt) {
//        Node* newNode = new Node(dt);
//
//        if(empty()) {
//           
//            head = newNode;
//            tail = newNode;
//        }
//        else {
//            
//            tail->next = newNode;
//            tail = newNode;
//        }
//    }
//
//    int pop() {
//        Node* curNode = head;
//       int re;
//        if(curNode == tail) {
//            head = NULL;
//            tail = NULL;
//            re = curNode->data ;
//            delete curNode;
//            
//        }
//        else{
//            
//            while(curNode->next != tail) {
//                curNode = curNode->next;
//            }
//            Node* delNode = tail;
//            tail = curNode;
//            curNode->next = NULL;
//            re = delNode->data;
//            delete delNode;
//                
//        }
//        return re;
//    }
//
//    int cal(string m) {
//        for(int i = 0; i < m.size(); i++) {
//            if(m[i] == '+') {
//            int x, y;
//            y = this->pop();
//            x = this->pop();
//            this->push(x + y);
//            }
//            else if(m[i] == '-' ) {
//            int x, y;
//            y = this->pop();
//            x = this->pop();
//            this->push(x - y);
//            }
//             else if(m[i] == '*'  ) {
//            int x, y;
//            y = this->pop();
//            x = this->pop();
//            this->push(x * y);
//            }
//            else {
//            this->push(m[i]-'0');
//            }
//           
//
//        }
//        return this->pop();
//    }
//
//};
//int main() {
//   int N;
//   cin >> N ;
//   StackList a;
//  
//   while (N--)
//   {
//       string M;
//       cin >> M;
//        cout << (a.cal(M) % 10) << endl;
//       
//     
//     
//       }
//   
//   
//
//   return 0;
//}
