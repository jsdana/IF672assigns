#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class BSTnode {
public:
    int key;
    BSTnode* left;
    BSTnode* right;

    BSTnode(){
        left = right = NULL;
    }
    BSTnode(int k, BSTnode* l = NULL, BSTnode* r = NULL){
        key = k; left = l; right = r;
    }
};

class BST{
private:
    BSTnode* root;
    int nodeCounter;

    void clearHelp(BSTnode* n){
        if(root == NULL)
            return;
        clearHelp(n->left);
        clearHelp(n->right);
        delete root;
    }

    BSTnode* insertHelp(BSTnode* n, int k, int e){
        if(n == NULL)
            return new BSTnode(k, NULL, NULL);
        if(n->key > k)
            n->left = insertHelp(n->left, k, e);
        else
            n->right = insertHelp(n->right, k, e);
        return n;
    }

    int findHelp(BSTnode* n, int k){
        if(n == NULL)
            return NULL;
        if(n->key > k)
            return findHelp(n->left, k);
        else if(n->key == k)
            return n->key;
        else  
            return findHelp(n->right, k);
    }

    BSTnode* getMin(BSTnode* n){
        if(n->left == NULL) return n;
        return getMin(n->left);
    }

    BSTnode* deleteMin(BSTnode* n){
        if(n->left == NULL) return n->right;
        n->left = deleteMin(n->left);
        return n;
    }

    BSTnode* removeHelp(BSTnode* n, int k){
        if(n == NULL) return NULL;
        if(n->key > k)
            n->left = removeHelp(n->left, k);
        else if(n->key < k)
            n->right = removeHelp(n->right, k);
        else{
            if(n->left == NULL) return n->right;
            else if(n->right == NULL) return n->left;
            else{
                BSTnode* temp = getMin(n->right);
                n->key = temp->key;
                n->right = deleteMin(n->right);
            }
        }
        return n;
    }

    void inOrder(BSTnode* n){
        if(n != NULL){
            inOrder(n->left);
            cout << n->key << " ";
            inOrder(n->right);
        }
    }

    void preOrder(BSTnode* n){
        if(n != NULL){
            cout << n->key << " ";
            preOrder(n->left);
            preOrder(n->right);
        }
    }

    void posOrder(BSTnode* n){
        if(n != NULL){
            posOrder(n->left);
            posOrder(n->right);
            cout << n->key << " ";
        }
    }

public:
    BST(){
        root = NULL;
        nodeCounter = 0;
    }
    ~BST() {clearHelp(root);}

    void insert(int e){
        int k = e;
        root = insertHelp(root, k, e);
        nodeCounter++;
    }

    int find(int k){
        return findHelp(root, k);
    }

    int remove(int k){
        int temp = findHelp(root, k);
        if(temp != NULL){
            root = removeHelp(root, k);
            nodeCounter--;
        }
        return temp;
    }

    void inPrint(){
        inOrder(root);
    }
    void prePrint(){
        preOrder(root);
    }
    void posPrint(){
        posOrder(root);
    }

};


int main(){
    BST now;
    int ops, num;
    cin >> ops;
    string op;
    for(int i=0; i<ops; i++){
        cin >> op;
        if(op == "pre")
            now.prePrint();
        else if(op == "in")
            now.inPrint();
        else if(op == "post")
            now.posPrint();
        else{
            cin >> num;
            now.insert(num);
        }
    }

    now.~BST();
    return 0;
}