//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//class Node {
//private:
//    Node* Par;
//    int data;
//    vector<Node*> chi_v;
//public:
//    Node(int dt) {
//        this->data = dt;
//        this->Par = NULL;
//    }
//    friend class Tree;
//};
//
//class Tree {
//private:
//    Node* root;
//    vector<Node*> node_v;
//
//public:
//    Tree(int dt) {
//        Node* newNode = new Node(dt);
//        this->root = newNode;
//        this->node_v.push_back(newNode);
//    }
//    // 부모( dt1)에 자식(dt2) 삽입
//    void Insert(int dt1, int dt2) {
//        if(dt1 == dt2) {
//            return;
//        }
//        Node* newNode = new Node(dt2);
//
//        for(int i = 0; i < node_v.size(); i++) {
//            if(node_v[i]->data == dt1) {
//                node_v[i]->chi_v.push_back(newNode);
//                node_v.push_back(newNode);
//                newNode->Par = node_v[i];
//
//                return ;
//            }
//
//        }
//        cout << -1 << endl;
//    }
//
//   
//
//
//    void level(int dt) {
//        Node* curNode;
//        int le1 = 1;
//        for (int i = 0; i <node_v.size(); i++ ) {
//            if(node_v[i]->data == dt) {
//                curNode = node_v[i];
//                for(int j = 0; j < node_v.size();j++) {
//                   
//                    if(curNode == root) {
//                        cout << le1 << endl;
//                        return;
//                    }
//                    
//                    curNode = curNode->Par;
//                    le1++;
//                    
//                }
//            }
//        }
//        cout << -1 << endl;
//    }
//
//
//
//};
//
//
//
//int main() {
//
//    Tree a(1);
//
//
//    int T , m;
//    cin >> T >> m;
//
//    for (int i = 0; i < T; i++) {
//        int dt1, dt2;
//        cin >> dt1 >> dt2;
//        
//        a.Insert(dt1, dt2);
//        
//    }
//    for (int j = 0; j < m; j++) {
//        int dt;
//        cin >> dt;
//        a.level(dt);
//    }
//    return 0;
//}
