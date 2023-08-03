#include <iostream>
#include <list>
#include <stack>

using namespace std;

#define VISITED 1
#define UNVISITED 0
#define NEW_EDGE 1

class Graph{
private:
    int** matrix;
    int* mark;
    int numEdge;
    int numVertex;
public:
    Graph(int nV, int nE){
        matrix = new int*[nV];
        for(int i=0; i<nV; i++){
            matrix[i] = new int[nV];
            for(int j = 0; j<nV; j++)
                matrix[i][j] = 0;
        }
        mark = new int[nE];

        numVertex = nV;
        numEdge = 0;
    }
    ~Graph(){
        for(int i=0; i<numVertex; i++)
            delete[] matrix[i];
        
        delete[] matrix;
        delete[] mark;        
    }

    void setEdge(int i, int j, int wt){
        if(wt == 0)
            return;
        if(matrix[i][j] == 0)
            numEdge++;
        matrix[i][j] = wt;
    }

    void setMark(int v, int val){
        mark[v] = val;
    }

    int getMark(int v){
        return mark[v];
    }

    int first(int v){
        for(int i=0; i<numVertex; i++)
            if(matrix[v][i] != 0)
                return i;
        return numVertex;
    }

    int next(int v, int w){
        for(int i = w+1; i<numVertex; i++)
            if(matrix[v][i] != 0)
                return i;
        return numVertex;
    }


    void topoSort(int v, stack<int> &s){
        setMark(v, VISITED);
        int w = first(v);
        while(w < numVertex){
            if(getMark(w) == UNVISITED)
                topoSort(w, s);
            w = next(v, w);
        }
        s.push(v);
        //cout << s.top() << " ";
    }

    void traverse(){
        stack<int> S;
        for(int v = 0; v<numVertex; v++)
            setMark(v, UNVISITED);

        for(int v=0; v<numVertex; v++){
            if(getMark(v) == UNVISITED){
                topoSort(v, S);
                
            } 
        }

        //cout << "\n";
        int size = S.size();
        //cout << S.size() << " ";
        if(S.size() == 0)
            cout << "EMPTY STACK";
        //cout << "\n";

        for(int i=0; i< size; i++){
            cout << S.top() << " ";
            S.pop();
        }

    }

    void printmatrix(){
        for(int i=0; i<numVertex; i++){
            for(int j=0; j<numVertex; j++)
                cout << matrix[i][j] << " ";
            cout << "\n";
        }
    }

};



int main(){

    int numV, numE, v1, v2;
    
    cin >> numV >> numE;
    Graph gr(numV, numV);
    for(int i=0; i<numE; i++){
        cin >> v1 >> v2;
        gr.setEdge(v1, v2, NEW_EDGE);
    }
    //gr.traverse();
    //gr.printmatrix();
    cout << "\n";
    gr.traverse();
 

    return 0;
}