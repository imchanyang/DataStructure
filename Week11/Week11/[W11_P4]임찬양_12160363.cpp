#include <iostream>
#include <string>

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
    
    int depth(int dt) {
        Node* curNode = this->root;
        int de = 0;
        while(curNode != NULL){
            if(dt == curNode->data) {
                return de;
            }
            else if(dt > curNode->data) {
                curNode = curNode->right;
                de++;
            }
            else {
                curNode = curNode->left;
                de++;
            }
        }
        
        return 0;
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
    

    int Min(Node* a) {
        
        
        while(a->left != NULL) {
            a = a->left;
        }
        
       
        int min = 0;
       min = a->data;
        
        
    
        return min;
        
        
    }
    
    
    
    void Delete(int dt) {
        Node* node = search(dt);
        
        if(node == NULL) {
            return;
        }
        
        if(node == root) {
            int dt_ = Min(node->right);
            node->data = dt_;
            Delete(dt_);


            return ;
        }
        
      
        
        Node* parN = node->par;
        
        

         if((node->left == NULL) && (node->right == NULL)) {
            if(parN->data < node->data) {
                parN->right = NULL;
                delete node;
            }
            else {
                parN->left = NULL;
                delete node;
            }
        }
        else if((node->left == NULL) && (node->right != NULL)) {
            if(parN->data < node->data) {
                node->right->par = parN;
                parN->right = node->right;
                delete node;
            }
            else {
                node->right->par = parN;
                parN->left = node->right;
                delete node;
            }
        }
        else if((node->left != NULL) && (node->right == NULL)) {
            if(parN->data < node->data) {
                node->left->par = parN;
                parN->right = node->left;
                delete node;
            }
            else {
                node->left->par = parN;
                parN->left = node->left;
                delete node;
            }
        }
        else {
            int dt_ = Min(node->right);

            Delete(dt_);
            node->data = dt_;

        }
    }
    

    

};

int main() {
    
    int T;
    cin >> T;
    BST a;
    while (T--) {
        
        string M;
        cin >> M;
        
        if(M == "insert") {
            int dt;
            cin >> dt;
            a.insert(dt);
        }
        else if(M == "depth") {
            int dt;
            cin >> dt;
            cout << a.depth(dt) << endl;
        }
        else if(M == "delete") {
            int dt;
            cin >> dt;
            a.Delete(dt);
        }
        
   
    }
    
    return 0;
}
