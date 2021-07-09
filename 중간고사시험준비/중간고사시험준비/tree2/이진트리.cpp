//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//class Node{
//private:
//    int data;
//    Node* par;
//    Node* left;
//    Node* rignt;
//public:
//    Node(int dt) {
//        data = dt;
//        par = NULL;
//        left = NULL;
//        rignt = NULL;
//    }
//    friend class Tree;
//};
//
//class Tree{
//private:
//    vector<Node*> nodes;
//    Node* root;
//    
//public:
//    Tree() {
//        root = new Node(1);
//        nodes.push_back(root);
//    }
//    
//    Node* Getroot() {
//        return root;
//    }
//    
//    void insertLeft(int pardt, int dt ) {
//        Node* newNode = new Node(dt);
//        for(auto NODE : nodes) {
//            if(NODE->data == pardt) {
//                NODE->left = newNode;
//                newNode->par = NODE;
//                nodes.push_back(newNode);
//            }
//        }
//    }
//    
//    void insertRight(int pardt, int dt ) {
//        Node* newNode = new Node(dt);
//        for(auto NODE : nodes) {
//            if(NODE->data == pardt) {
//                NODE->rignt = newNode;
//                newNode->par = NODE;
//                nodes.push_back(newNode);
//            }
//        }
//    }
//    
//    void postOrder(Node* a) {
//        if(a->left != NULL ) {
//        postOrder(a->left);
//        
//        }
//        if(a->rignt != NULL) {
//            postOrder(a->rignt);
//        }
//        cout << a->data << " ";
//    }
//    
//    void inOrder(Node* a) {
//        if(a->left != NULL ) {
//        inOrder(a->left);
//        }
//        
//        cout << a->data << " ";
//        
//        if(a->rignt != NULL) {
//            inOrder(a->rignt);
//        }
//    }
//    
//    void preOrder(Node* a) {
//        
//        cout << a->data << " ";
//        
//        if(a->left != NULL ) {
//        preOrder(a->left);
//        }
//        
//        if(a->rignt != NULL) {
//            preOrder(a->rignt);
//        }
//    }
//    
//};
//
//int main() {
//    
//    Tree a;
//    
//    a.insertLeft(1, 2);
//    a.insertRight(1, 3);
//    a.insertLeft(2, 4);
//    a.insertRight(2, 5 );
//    a.insertLeft(3, 6);
//    a.insertRight(3, 7 );
//    
//    a.postOrder(a.Getroot());
//    cout << endl;
//    
//    a.inOrder(a.Getroot());
//    cout << endl;
//    a.preOrder(a.Getroot());
//    return 0;
//}
