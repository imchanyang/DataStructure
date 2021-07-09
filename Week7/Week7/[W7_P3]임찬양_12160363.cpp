#include <iostream>
#include <vector>

using namespace std;

class Node {
private:
    int data;
    Node* par;
    vector<Node*> child;
public:
    Node(int dt){
        this->data = dt;
        this->par = NULL;
    }
    
    friend class Tree;
};

class Tree {
private:
    
    vector<Node*> nodes;
    
public:
    Node* root;
    Tree(int dt) {
        Node* node = new Node(dt);
        root = node;
        nodes.push_back(node);
    }
    
    void insert(int pardt, int dt) {
        Node* newNode = new Node(dt);
        
        for(int i = 0; i < nodes.size();i++) {
            if (nodes[i]->data == pardt) {
                nodes[i]->child.push_back(newNode);
                newNode->par = nodes[i];
                nodes.push_back(newNode);
                return;
            }
        }
    }
    
    void PrintPostpar(Node* node){
        if(!node) {
            
            return;
        }
        else{
            for(int i = 0; i < node->child.size(); i++) {
                PrintPostpar(node->child[i]);
            }
            if(node == root) {
                cout << 0 << endl;
            }
            else {
            cout << node->par->data << " ";
            }
           
        }
        
    }
};


int main() {
    
    
    int T;
    cin >> T;
    
    for(int i = 0; i < T; i++) {
        Tree a(1);
        int N;
        cin >> N;
        for(int j = 0; j < N; j++) {
            int pardt, dt;
            cin >> pardt >> dt;
            a.insert(pardt, dt);
        }
        a.PrintPostpar(a.root);
    }
    return 0;
}
