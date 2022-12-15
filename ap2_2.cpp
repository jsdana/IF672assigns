#include <iostream>
using namespace std;

void getArr(int Arr[], int size){
    for(int i=0; i<size; i++)
        cin >> Arr[i];
}

void printArr(int Arr[], int size){
    for(int i=0; i<size; i++)
        cout << Arr[i] << " ";
}

int biSearch(int A[], int l, int r, int K){
    int m;
    if(r>=l){
        m = (l+r)/2;
        if(K == A[m])
            return m;
        else if(K < A[m])
            return biSearch(A, l, m-1, K);
        else
            return biSearch(A, m+1, r, K);
    }else
        return -1;
}

void result(int keysArr[], int nKeys, int Arr[], int sizeArr){
    int result;
    for(int i=0; i<nKeys; i++){
        result = biSearch(Arr, 0, sizeArr-1, keysArr[i]);
        if(result == -1)
            cout << 'x' << endl;
        else
            cout << result << endl;
    }
}

int main(){

    int sizeOfArr, nKeys;

    cin >> sizeOfArr;
    int* sortedArr = new int[sizeOfArr];
    getArr(sortedArr, sizeOfArr);

    cin >> nKeys;
    int* keysArr = new int[nKeys];
    getArr(keysArr, nKeys);

    cout << endl << endl;
    result(keysArr, nKeys, sortedArr, sizeOfArr);

    delete[]sortedArr;
    sortedArr = NULL;

    delete[]keysArr;
    keysArr = NULL;

    return 0;
}
