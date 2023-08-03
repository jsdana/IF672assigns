#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Link{
public:
    int element;
    Link* next;

    Link(const int& val, Link* prox = NULL){
        element = val; next = prox;
    }
    Link(Link* prox = NULL){
        next = prox;
    }
};

class llist{
private:
    Link* head;
    Link* curr;
    Link* tail;
    int cnt;
public:
    llist(){
        head = curr = tail = new Link();
        cnt = 0;
    }
    ~llist(){clear();}

    void clear(){
        while(head!=NULL){
            curr = head;
            head = head->next;
            delete curr;
        }
    }

    void append(const int& it){
        tail = tail->next = new Link(it, NULL);
        cnt++;
    }

    int remove(){
        if(curr->next!=NULL){
            int it = curr->next->element;
            Link* temp = curr->next;
            if(tail==curr->next)
                tail = curr;
            curr->next = curr->next->next;
            delete temp;
            cnt--;
            return it;
        }
    }

    const int& getVal() const{
        if(tail!=NULL)
            return tail->element;
    }

    void print(){
        curr = head;
        for(int i=0; i<cnt; i++){
            cout << curr->next->element << " ";
            curr = curr->next;
        }
    }
    bool findOne(int k){
        curr = head;
        for(int i=0; i<cnt; i++){
            if(curr->next->element == k)
                return true;
            else
                curr = curr->next;
        }
        return false;
    }

};

class Dictionary{
private:
    int m;
    int cnt;
    llist* H;
public:
    Dictionary(int size){
        m = size; cnt = 0;
        H = new llist[10];
    }
    ~Dictionary(){
        for(int i=0; i<10; i++)
            H->~llist();
        delete [] H;
    }

    int h(int k){
        return abs(k%10);
    }

    bool find(int k){
        for(int i=0; i<10;i++){
            if(H[i].findOne(k))
                return true;
        }
        return false;
    }

    void insert(int e){
        if(!find(e)){
            int pos = h(e);
            H[pos].append(e);
        }
    }
    void printD(){
        for(int i=0; i<10; i++){
            cout << i << " ";
            H[i].print();
            cout << endl;
        }
    }
};


int main(){
    int size, atual;
    cin >> size;
    Dictionary seis(size);
    for(int i=0; i<size; i++){
        cin >> atual;
        seis.insert(atual);
    }
    seis.printD();
    
    seis.~Dictionary();
    return 0;
}