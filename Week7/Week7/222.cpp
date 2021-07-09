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
//    void InitTree(Node *bst)
//    {
//        *bst = NULL;
//    }
//};
//
//
//int main() {
//    
//    vector<int> postorder_;
//    vector<int> depth_;
//    
//    
//    int T;
//    cin >> T;
// 
//   
//    for(int i = 0; i < T; i++) {
//        int rem1 = 0;
//        int rem2 = 0;
////        Node* b = a.root;
//        
//        Tree a(1);
//        int N;
//        cin >> N;
//        for(int j = 0; j < N; j++) {
//            int dt;
//            cin >> dt;
//            postorder_.push_back(dt);
//        }
//        for(int k = 0; k < N; k++) {
//            int dt;
//            cin >> dt;
//            depth_.push_back(dt);
//        }
//        
//        for(int g = 0; g < N; g++ ) {
//            if(depth_[g] == 1) {
////                postorder_[g]
//                
//                a.insert(1, postorder_[g]);
//                for(int h = rem1; h < g; h++) {
//                    if(depth_[h] == 2) {
//                        a.insert(postorder_[g],postorder_[h]);
//                        rem1 = g;
//                        for(int r = rem2; r < h; r++) {
//                            if(depth_[r] == 3) {
//                                a.insert(postorder_[h], postorder_[r]);
//                                rem2 = h;
//                            }
//                        }
//                    }
//                }
//                
//            }
//        }
//        a.Printpre(a.root);
//        a.root->child.clear();
//        a.nodes.clear();
//        cout << endl;
//        
//    
//        
//    }
//    return 0;
//}
