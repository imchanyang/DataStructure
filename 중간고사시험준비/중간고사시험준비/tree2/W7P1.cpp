//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//class Node{
//private:
//    int data;
//    Node* par;
//    vector<Node*> child;
//public:
//    Node(int dt) {
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
//    Tree() {
//        root = new Node(1);
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
////    void preOrder(Node* find) {
////
////        if(find->par == NULL) {
////            cout << 0 << " " ;
////        }
////        else {
////            cout << find->par->data << " ";
////        }
////
////        for(Node* Nodes : find->child) {
////            preOrder(Nodes);
////        }
////
////    }
//    void preOrder(Node* find) {
//     
//        
//            cout << find->data << " ";
//        
//        
//        for(Node* Nodes : find->child) {
//            preOrder(Nodes);
//        }
//        
//    }
//            
//            
//};
//
//int main() {
//    
//    
//    int T;
//    cin >> T;
//    while (T--) {
//        Tree a;
//        int N;
//        cin >> N;
//        
//        while (N--) {
//            int dt1 , dt2;
//            cin >> dt1 >> dt2;
//            
//            a.insert(dt1, dt2);
//          
//            
//        }
//        a.preOrder(a.getRoot());
//        cout << endl;
//    }
//    
//    return 0;
//}
