#include <iostream>
#include <vector>
using namespace std;

void getVector(vector<int> *vect, int rows){
    int rowSize, currValue;
    for(int i=0; i<rows; i++){
        cin >> rowSize;
        for(int j=0; j<rowSize; j++){
            cin >> currValue;
            vect[i].push_back(currValue);
        }
    }
}

void printVect(vector<int> *vect, int rows){
    for(int i=0; i<rows; i++){
        for(int j=0; j<vect[i].size(); j++)
            cout << vect[i][j] << " ";
        cout << endl;
    }
}

void swap(vector<int> *vect, int i, int j, int row){
    int temp;
    temp = vect[row][i];
    vect[row][i] = vect[row][j];
    vect[row][j] = temp;
}

int hoarePartition(vector<int> *vect, int l, int r, int row){
    int p, i, j;
    p = vect[row][l]; i = l; j = r+1;

    do{
        do{
            i = i+1;
        }while(vect[row][i]>p && i<r);
        do{
            j = j-1;
        }while(vect[row][j]<p);
        swap(vect, i, j, row);
    }while(i<j);

    swap(vect, i, j, row);
    swap(vect, l, j, row);
    return j;
}

void quickSort(vector<int> *vect, int l, int r, int row){
    int s;
    if(l<r){
        s = hoarePartition(vect, l, r, row);
        quickSort(vect, l, s-1, row);
        quickSort(vect, s+1, r, row);
    }
}

void quickSortVect(vector<int> *vect, int rows){
    for(int i=0; i<rows; i++)
        quickSort(vect, 0, vect[i].size()-1, i);
}

int main(){

    int rows;
    cin >> rows;
    vector<int> vetor[rows];

    getVector(vetor, rows);
    int n = vetor[0].size();
    quickSortVect(vetor, rows);

    cout << endl;

    printVect(vetor, rows);

    return 0;
}
