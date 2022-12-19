#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void getNames(string fileName, vector<string> &list){
    ifstream file;
    file.open(fileName);
    string curr;
    if(file.is_open()){
        while(file.good()){
            file >> curr;
            list.push_back(curr);
        }
    }
    file.close();
}

void printNames(vector<string> &nameslist){
    for(int i=0; i< nameslist.size(); i++)
        cout << nameslist[i] << endl;
}

void swap(vector<string> &v, int i, int j){
    string temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int hoarePartition(vector<string> &v, int l, int r){
    string p = v[l];
    int i = l, j = r+1;
    do{
        do{
            i = i+1;
        }while(!(v[i]>=p || i>=r));
        do{
            j = j-1;
        }while(!(v[j]<=p));
        swap(v, i, j);
    }while(!(i>=j));

    swap(v, i, j);
    swap(v, l, j);
    return j;
}

void quickSort(vector<string> &v, int l, int r){
    int s;
    if(l<r){
        s = hoarePartition(v, l, r);
        quickSort(v, l, s-1);
        quickSort(v, s+1, r);
    }
}

void createNewFile(string fileName, vector<string> &vect){
    ofstream file;
    file.open(fileName);
    if(!file)
        cout << "File not found";
    else{
        for(int i=0; i<vect.size(); i++)
            file << vect[i] << endl;
        file.close();
    }
}

int main(){

    vector<string> namesList;
    getNames("names.txt", namesList);
    quickSort(namesList, 0, namesList.size()-1);
    createNewFile("newFile.txt", namesList);

    return 0;
}
