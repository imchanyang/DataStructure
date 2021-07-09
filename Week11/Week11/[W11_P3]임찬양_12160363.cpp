#include <iostream>

using namespace std;



class Node{
private:
    int data;
    Node* par;
    Node* left;
    Node* right;
public:
    Node(int dt) {
        data = dt;
        par = NULL;
        left = NULL;
        right = NULL;
    }
    
    void setLeft(Node* node) {
        if(node == NULL) {
            this->left = NULL;
        }
        else {
            this->left = node;
            node->par = this;
        }
    }
    
    void setRight(Node* node) {
        if(node == NULL) {
            this->right = NULL;
        }
        else {
            this->right = node;
            node->par = this;
        }
    }
    
    friend class BST;
};


class BST{
private:
    Node* root;
public:
    BST() {
        this->root = NULL;
    }
    
    Node* search(int dt) {
        Node* curNode = this->root;
        
        while(curNode != NULL){
            if(dt == curNode->data) {
                return curNode;
            }
            else if(dt > curNode->data) {
                curNode = curNode->right;
            }
            else {
                curNode = curNode->left;
            }
        }
        
        return NULL;
    }
    
    void insert(int dt) {
        Node* newNode = new Node(dt);
        
        if(root == NULL) {
            root = newNode;
            return;
        }
        
        Node* parNode = NULL;
        Node* curNode = root;
        	
        while(curNode != NULL) {
            if(dt > curNode->data) {
                parNode = curNode;
                curNode = curNode->right;
            }
            else {
                parNode = curNode;
                curNode = curNode->left;
            }
        }
        
        if(dt > parNode->data) {
            parNode->setRight(newNode);
        }
        else if(dt < parNode->data) {
            parNode->setLeft(newNode);
        }
    }
    
    void print(Node* a) {
        if(a->left != NULL) {
            print(a->left);
        }
        
        cout << a->data << " ";
        
        if(a->right != NULL) {
            print(a->right);
        }
    }
    
    Node* getRoot() {
        return root;
    }

    

};

int main() {
    
    int T;
    cin >> T;
    
    while (T--) {
        BST a;
        int N;
        cin >> N;
        
        for(int i = 0; i < N; i++) {
            int dt;
            cin >> dt;
            a.insert(dt);
        }
        
        a.print(a.getRoot());
        cout << endl;
        
   
    }
    
    return 0;
}
