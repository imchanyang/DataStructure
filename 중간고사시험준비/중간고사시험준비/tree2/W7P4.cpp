#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node{
private:
    int data;
    Node* par;
    
public:
    vector<Node*> child;
    Node(int dt) {
        data = dt;
        par = NULL;
    }
    friend class Tree;
};

class Tree{
private:
    vector<Node*> nodes;
    Node* root;
public:
    Tree() {
        root = new Node(1);
        nodes.push_back(root);
    }

    Node* getRoot() {
        return root;
    }

    void insert(int pardt, int dt) {
        Node* newNode = new Node(dt);
        for(Node* Nodes : nodes ) {
            if(Nodes->data == pardt) {
                Nodes->child.push_back(newNode);
                newNode->par = Nodes;
                nodes.push_back(newNode);
            }
        }

    }

        void preOrder(Node* find) {
    
          
                cout << find->data << " ";
       
    
            for(Node* Nodes : find->child) {
                preOrder(Nodes);
            }
    
        }


};

int main() {

    
    
    int T;
    cin >> T;
    
    while (T--) {
        
        vector<Node*> Wait[1'000];
        Tree a;
        int N;
        cin >>N;
        int postdt[N];
        int depth[N];
        Node* newNode = NULL;
        for(int i = 0 ; i < N; i++) {
            
            cin >> postdt[i];
        }
        
        for(int j = 0; j < N; j++) {
            
            cin >> depth[j];
            
            newNode = new Node(postdt[j]);
            
            if(j == 0) {
                Wait[depth[j]].push_back(newNode);
            }
            else {
                if(depth[j-1] -1 == depth[j]) {
                    Wait[depth[j]].push_back(newNode);
                    for(auto child_ : Wait[depth[j-1]]) {
                        newNode->child.push_back(child_);
                    }
                    Wait[depth[j-1]].clear();
                }
                else {
                    Wait[depth[j]].push_back(newNode);
                }
            }
            
            
        }
        a.preOrder(newNode);
        cout << endl;

        
    }
    return 0;
}
