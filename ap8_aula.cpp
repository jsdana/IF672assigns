#include <iostream>
#include <stdlib.h>

using namespace std;

class BSTNode{
public:
    int key;
    int element;
    int height;
    BSTNode* left;
    BSTNode* right;

    BSTNode(){
        left = right = NULL;
    }
    BSTNode(int k, int e, BSTNode* l, BSTNode* r){
        key = k; element = e; height = 0; left = l; right = r;
    }
};

class BST{
private:
    BSTNode* root;
    int nodeCount;

    void clearHelp(BSTNode* n){
        if(n==NULL)
            return;
        clearHelp(n->left);
        clearHelp(n->right);
        delete n;
    }

    BSTNode* insertHelp(BSTNode* n, int k, int e){
        if(n==NULL)
            return new BSTNode(k, e, NULL, NULL);
        if(n->key>k)
            n->left = insertHelp(n->left, k, e);
        else
            n->right = insertHelp(n->right, k, e);

        n->height = max(h(n->left), h(n->right)) + 1;
        int balance = getBalance(n);
        if(balance < -1 && k>= n->right->key)
            return leftRotate(n);
        if(balance > 1 && k< n->left->key)
            return rightRotate(n);
        if(balance >1 && k>= n->left->key){
            n->left = leftRotate(n->left);
            return rightRotate(n);
        }
        if(balance < -1 && k< n->right->key){
            n->right = rightRotate(n->right);
            return leftRotate(n);
        }
        return n;
    }

    void PrintIn(BSTNode* n){
        if(n!=NULL){
            PrintIn(n->left);
            cout << n->element << " ";
            PrintIn(n->right);
        }
    }

    void PrintPre(BSTNode* n){
        if(n!=NULL){
            cout << n->element << " ";
            PrintPre(n->left);
            PrintPre(n->right);
        }
    }

    int h(BSTNode* n){
        if(n==NULL)
            return -1;
        return n->height;
    }

    int getBalance(BSTNode* n){
        if(n==NULL)
            return 0;
        return h(n->left) - h(n->right);
    }

    BSTNode* rightRotate(BSTNode* n){
        BSTNode* l = n->left;
        BSTNode* lr = l->right;
        l->right = n;
        n->left = lr;
        n->height = max(h(n->left), h(n->right)) + 1;
        l->height = max(h(l->left), h(l->right));
        return l;
    }

    BSTNode* leftRotate(BSTNode* n){
        BSTNode* r = n->right;
        BSTNode* rl = r->left;
        r->left = n;
        n->right = rl;
        n->height = max(h(n->left), h(n->right)) + 1;
        r->height = max(h(r->left), h(r->right)) + 1;
        return r;
    }

public:
    BST(){
        root = NULL;
        nodeCount = 0;
    }
    ~BST(){ clearHelp(root); }

    void insert(int k, int e){
        root = insertHelp(root, k, e);
        nodeCount++;
    }

    void Print_Inorder(){
        PrintIn(root);
    }
    void Print_Preorder(){
        PrintPre(root);
    }

};

int main(){
    BST al;
    int temp;
    while(cin >> temp){
        al.insert(temp, temp);
    }

    al.Print_Preorder();

    return 0;
}