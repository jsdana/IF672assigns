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

void printVector(vector<int> *vect, int rows){
    for(int i=0; i<rows; i++){
        for(int j=0; j<vect[i].size(); j++)
            cout << vect[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void merge(vector<int> *vect, int l, int r, int currRow){
    int m, i1, i2;
    int temp[l+r+1];
    
    for(int i=l; i<=r; i++)
        temp[i] = vect[currRow][i];
        
    m = (r+l)/2; i1 = l; i2 = m+1;
    
    for(int curr=l; curr<=r; curr++){
        if(i1==(m+1))
            vect[currRow][curr] = temp[i2++];
        else if(i2>r)
            vect[currRow][curr] = temp[i1++];
        else if(temp[i1]<=temp[i2])
            vect[currRow][curr] = temp[i1++];
        else
            vect[currRow][curr] = temp[i2++];
    }
}

void mergeSort(vector<int> *vect, int l, int r, int currRow){
    int m;
    if(l<r){
        m = (l+r)/2;
        mergeSort(vect, l, m, currRow);
        mergeSort(vect, m+1, r, currRow);
        merge(vect, l, r, currRow);
    }
}

void mergeSortVect(vector<int> *vect, int rows){
    for(int i=0; i<rows; i++){
        mergeSort(vect, 0, vect[i].size()-1, i);
    }
}

int main()
{
    int rows;
    cin >> rows;
    vector<int> vetor[rows];
    
    getVector(vetor, rows);
    cout << endl<< endl;
    mergeSortVect(vetor, rows);
    printVector(vetor, rows);

    return 0;
}
