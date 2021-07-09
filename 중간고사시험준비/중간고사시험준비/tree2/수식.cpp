//#include <iostream>
//#include <string>
//#include <vector>
//#include <stack>
//
//using namespace std;
//
//class Node{
//private:
//    char data;
//    Node* par;
//
//public:
//    vector<Node*> child;
//    Node(char dt) {
//        data = dt;
//        par = NULL;
//    }
//    friend class Tree;
//};
//
//class Tree{
//private:
//    vector<Node*> nodes;
//    Node* root;
//public:
//    Tree(Node* a) {
//        root = a;
//        nodes.push_back(root);
//    }
//
//    Node* getRoot() {
//        return root;
//    }
//
//    void insert(int pardt, int dt) {
//        Node* newNode = new Node(dt);
//        for(Node* Nodes : nodes ) {
//            if(Nodes->data == pardt) {
//                Nodes->child.push_back(newNode);
//                newNode->par = Nodes;
//                nodes.push_back(newNode);
//            }
//        }
//
//    }
//
//        void postOrder(Node* find) {
//            for(Node* Nodes : find->child) {
//                postOrder(Nodes);
//            }
//
//                cout << find->data << " ";
//
//
//        }
//    
//    void preOrder(Node* find) {
//       
//            cout << find->data << " ";
//           
//        for(Node* Nodes : find->child) {
//            preOrder(Nodes);
//            
//        }
//       
//        }
//    
//    int evalF(Node* find) {
//        int x[2];
//        int i = 0;
//        char y ;
//        for(Node* Nodes : find->child) {
//            
//            x[i] = evalF(Nodes);
//            i++;
//            y=find->data;
//        }
//        if(y == '+') {
//            return x[0] + x[1];
//        }
//        else if(y == '-') {
//            return x[0] - x[1];
//        }
//        else if(y == '*') {
//            return x[0] * x[1];
//        }
//        else if(y == '/') {
//            return x[0] / x[1];
//        }
//        else {
//        return find->data - '0';
//        }
//    }
//       
//        
//
//
//};
//
//class StackArr{
//    private:
//    char* arr;
//    int capacity;
//    int t;
//
//    public:
//    StackArr(int capa) {
//        capacity = capa;
//        arr = new char[capacity];
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
//    void push(char dt) {
//        if(t == (capacity-1)) {
//            cout << "FULL" << endl;
//        }
//        else {
//        t++;
//        arr[t] = dt;
//        }
//
//    }
//    char pop() {
//       
//        int temp = t;
//        t--;
//        return arr[temp];
//           
//        
//    }
//
//
//};
//
//int main() {
//
//
//    StackArr a(10);
//    string M;
//    cin >> M;
//    Node* newNode = NULL;
//    
//    vector<Node*> li;
//    for(int i = 0; i<M.length(); i++) {
//        
//        if(M[i] == '*' || M[i] == '/' || M[i] == '+' || M[i] == '-') {
//            if(i == M.length() - 1) {
//               newNode = new Node(M[i]);
//               for(auto child_ : li) {
//                   newNode->child.push_back(child_);
//                   
//               }
//            }
//            else{
//            char a1 = a.pop();
//            char a2 = a.pop();
//            newNode = new Node(M[i]);
//            Node* n1 = new Node(a2);
//            Node* n2 = new Node(a1);
////            li.push_back(n1);
////            li.push_back(n2);
//          
//
//            
//            newNode->child.push_back(n1);
//            newNode->child.push_back(n2);
//                li.push_back(newNode);
//           
//            }
//       
//        }
//        else {
//        a.push(M[i]);
//        }
//    }
//    Tree d(newNode);
//    d.postOrder(d.getRoot());
//    cout << endl;
//    d.preOrder(d.getRoot());
//    cout << endl;
//    cout << d.evalF(d.getRoot()) << endl;
//    return 0;
//}
//
