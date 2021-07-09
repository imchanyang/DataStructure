//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//class Node {
//private:
// 
//public:
//    int data;
//    Node* par;
//    vector<Node*> child;
//    Node(int dt){
//        this->data = dt;
//        this->par = NULL;
//    }
//    
//    friend class Tree;
//};
//
//class Tree {
//private:
//    
//    
//    
//public:
//    vector<Node*> nodes;
//    Node* root;
//    Tree(int dt) {
//    
////        root->child.clear();
////        nodes.clear();
//        Node* node = new Node(dt);
//        root = node;
//
//        nodes.push_back(node);
//    }
//    
//    void insert(int pardt, int dt) {
//        Node* newNode = new Node(dt);
//        
//        for(int i = 0; i < nodes.size();i++) {
//            if (nodes[i]->data == pardt) {
//                nodes[i]->child.push_back(newNode);
//                newNode->par = nodes[i];
//                nodes.push_back(newNode);
//                return;
//            }
//        }
//    }
//    
//    void PrintPostpar(Node* node){
//        if(!node) {
//            
//            return;
//        }
//        else{
//            for(int i = 0; i < node->child.size(); i++) {
//                PrintPostpar(node->child[i]);
//            }
//            if(node == root) {
//                cout << 1 << endl;
//            }
//            else {
//            cout << node->data << " ";
//            }
//           
//        }
//        
//    }
//    
//    void Printpre(Node* node) {
//        if(!node) {
//          
//            return;
//        }
//        else {
//           
//                
//            cout << node->data << " ";
//            
//            for(int i = 0; i < node->child.size(); i++) {
//                Printpre(node->child[i]);
//            }
//        }
//    }
//    
//};
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
//    int top() {
//        if(empty()) {
//            return -1;
//            
//        }
//        else {
//            
//            return arr[t];
//        }
//    }
//
//    void push(int dt) {
//        if(size() == capacity) {
//            cout << "FULL" << endl;
//        }
//        
//        t++;
//        arr[t] = dt;
//    }
//
//    int pop() {
//        if(empty()) {
//            return -1;
//        }
//        else {
//
//
//            
//            int temp = arr[t];
//            arr[t] = 0;
//            t--;
//            return temp;
//        }
//    }
//
//};
//
//
//
//int main() {
//    
//
//    
//    int T;
//    cin >> T;
//    for (int i = 0; i < T; i++) {
//        int N;
//        cin >> N;
//        int tree[N];
//        Stackarr a(N);
//        
//        for(int j = 0; j < N; j++) {
//            int dt;
//            cin >> dt;
//            tree[i] = dt;
//        }
//        
//        for(int k = 0; k < N; k ++) {
//            int dp;
//            cin >> dp;
//            if(a.top() < dp) {
//                a.pop();
//                
//            }
//            a.push(dp);
//        }
//        
//    }
//
//    return 0;
//}
