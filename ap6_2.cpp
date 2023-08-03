#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

const int tam = 10;

class Dictionary{
private:
    int m;
    int cnt;
    string* H;
    int* perm;
public:
    Dictionary(int size){
        m = size; cnt = 0;
        H = new string[tam];
        perm = new int[tam];
        for(int i=0; i<tam; i++){
            H[i] = "NULL";
            perm[i] = rand()%tam;
        }
    }
    ~Dictionary(){
        delete [] H;
        delete [] perm;
    }

    bool find(string k){
        for(int i=0; i<tam; i++){
            if(H[i] == k)
                return true;
        }
        return false;
    }
    int findP(string k){
        for(int i=0; i<tam; i++)
            if(H[i] == k)
                return i;
        return -1;
    }

    int h(string k){
        int s = k.size();
        int sum = 0;
        for(int i=0; i<s; i++)
            sum += k.at(i);
        return abs(sum%m);
    }

    void insert(string e){
        if(cnt < m && !find(e)){
            int pos = h(e);
            int offset, newPos;
            if(H[pos] != "NULL" && H[pos] != "-1"){
                int i = 0;
                do{
                    i++;
                    offset = perm[i-1];
                    newPos = (pos + offset)%m;
                }while(!(H[newPos] == "NULL" || H[newPos] == "-1"));
                pos = newPos;
            }
            
            H[pos] = e;
            cnt++;
        }
    }

    void remove(string k){
        for(int i=0; i<tam; i++){
            if(H[i] == k)
                H[i] = "-1";
        }
    }

    void print(){
        for(int i=0; i<tam; i++){
            if(H[i] != "NULL")
                cout << H[i] << " ";
        }
    }

    void priPerm(){
        for(int i=0; i<tam; i++){
            cout << perm[i] << " ";
        }
    }
};

int main(){
    int size;
    string op, pala;
    cin >> size;
    Dictionary seis_dois(size);
    do{
        cin >> op;
        if(op!="fim"){
            cin >> pala;
            if(op == "add"){
                seis_dois.insert(pala);
            }else if(op == "rmv"){
                seis_dois.remove(pala);
            }else if(op == "sch"){
                cout << pala << " " << seis_dois.findP(pala) << endl;
            }
        }
    }while(op != "fim");

    seis_dois.~Dictionary();
    return 0;
}