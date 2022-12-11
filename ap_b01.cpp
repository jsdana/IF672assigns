#include <iostream>
#include<vector>

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
}

void merge(vector<int> *vect, int currRow, int left, int mid, int right){
    int subA1 = mid+1-left;
    int subA2 = right-mid;

    int *leftArray = new int[subA1];
    int *rightArray = new int[subA2];

    for(int i=0; i<subA1; i++)
        leftArray[i] = vect[currRow][left+i];
    for(int j=0; j<subA2; j++)
        rightArray[j] = vect[currRow][mid+1+j];

    int idxSubA1 = 0, idxSubA2 = 0, idxMergedA = left;

    while(idxSubA1<subA1 && idxSubA2<subA2){
        if(leftArray[idxSubA1] <= rightArray[idxSubA2]){
            vect[currRow][idxMergedA] = leftArray[idxSubA1];
            idxSubA1++;
        }else{
            vect[currRow][idxMergedA] = rightArray[idxSubA2];
            idxSubA2++;
        }
        idxMergedA++;
    }

    while(idxSubA1 < subA1){
        vect[currRow][idxMergedA] = leftArray[idxSubA1];
        idxSubA1++;
        idxMergedA++;
    }
    while(idxSubA2 < subA2){
        vect[currRow][idxMergedA] = rightArray[idxSubA2];
        idxSubA2++;
        idxMergedA++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

void mergeSort(vector<int> *vect, int currRow, int begin, int end){
    if(begin >= end)
        return;
    
    int mid = begin + (end - begin)/2;
    mergeSort(vect, currRow, begin, mid);
    mergeSort(vect, currRow, mid+1, end);
    merge(vect, currRow, begin, mid, end);
}

int main(){

    int rows, currSize;
    cin >> rows;
    
    vector<int>vetor[rows];
    getVector(vetor, rows);

    for(int i=0; i<rows; i++){
        currSize = vetor[i].size();
        mergeSort(vetor, i, 0, currSize-1);
    }

    cout << endl << endl;

    printVector(vetor, rows);

    return 0;
}
