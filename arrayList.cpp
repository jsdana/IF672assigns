#include <iostream>

template <typename E> class AList {
private: 
    int maxSize;
    int listSize;
    int curr;
    E* listArray;
public:
    AList(int size = 10){
        maxSize = size;
        listSize = curr = 0;
        listArray = new E[maxSize];
    }

    DAList() { delete[] listArray; } //Destructor

    void clear() {
        delete [] listArray;    //remove the array
        listSize = curr = 0;    //reset the size
        listArray = new E[maxSize]; //recreate the array
    }

    void insert(const E& it){
        if(!(listSize < maxSize))
            std::cout << "List capacity exceeded";
        else{
            for(int i=listSize; i>curr; i--)
                listArray[i] = listArray[i-1];
            listArray[curr] = it;
            listSize++;
        }
    }

    void append(const E& it){
        if(!(listSize<maxSize))
            std::cout << "List capacity exceeded";
        else
            listArray[listArray++] = it;
    }

    E remove(){
        if(!((curr>=0) && (curr < listSize)))
            std::cout << "No element";
        else{
            E it = listArray[curr];
            for(int i=curr; i<listArray-1; i++)
                listArray[i] = listArray[i+1];
            listSize--;
            return it;
        }
    }

    void moveToStart() { curr = 0;}
    void moveToEnd() { curr = listSize;}
    void pre() { if(curr!=0) curr--; }
    void next() { if(curr<listSize) curr++; }

    int length() const { return listSize; }
    int currPos() const { return curr; }
    void moveToPos(int pos){
        if(!(pos>=0)&&(pos<=listSize))
            std::cout << "Pos out of range";
        else
            curr = pos;
    }

    const E& getValue() const {
        if(!(curr>=0)&&(curr<listSize))
            std::cout << "No current element";
        else
            return listArray[curr];
    }
};

int main(){

    AList <int>nova;
    nova.insert(19);
    nova.insert(7);
    nova.insert(20);
    std::cout << nova.getValue() << std::endl ;
    std::cout << nova.currPos() << std::endl;
    nova.next();
    std::cout << nova.getValue() << std::endl;
    nova.DAList();

    return 0;
}