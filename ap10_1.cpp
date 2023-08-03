#include <iostream>
#include <stdlib.h>
#include <queue>
#include <string>

using namespace std;

#define UNVISITED 0
#define VISITED 1
#define NEW_EDGE 1

class Graph{
private:
    int** matrix;
    int numVertex;
    int numEdge;
    int* mark;
public:
    Graph(int n){
        mark = new int[n];
        matrix = new int*[n];
        for(int i=0; i<n; i++){
            matrix[i] = new int[n];
            for(int j = 0; j<n; j++)
                matrix[i][j] = 0;
        }
        numVertex = n;
        numEdge = 0;
    }
    
    ~Graph(){
        delete[] mark;
        for(int i=0; i<numVertex; i++){
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    int n(){
        return numVertex;
    }

    int e(){
        return numEdge;
    }

    int first(int v){
        for(int i=0; i<numVertex; i++)
            if(matrix[v][i] != 0)
                return i;
        return numVertex;
    }

    int next(int v, int w){
        for(int i = w+1; i < numVertex; i++)
            if(matrix[v][i] != 0)
                return i;
        return numVertex;
    }

    void setEdge(int i, int j, int wt){
        if(wt == 0)
            return;
        if(matrix[i][j] == 0)
            numEdge++;
        matrix[i][j] = wt;
        matrix[j][i] = wt;
    }

    void delEdge(int i, int j){
        if(matrix[i][j] != 0)
            numEdge--;
        matrix[i][j] = 0;
    }

    bool isEdge(int i, int j){
        if(matrix[i][j] != 0)
            return true;
        return false;
    }

    void setMark(int v, int val){
        mark[v] = val;
    }

    int getMark(int v){
        return mark[v];
    }

    void DFS(int v){
        //preVisit(int v);
        cout << v << " ";
        setMark(v, VISITED);
        int w = first(v);
        while(w < numVertex){
            if(getMark(w) == UNVISITED)
                DFS(w);
            w = next(v, w);
        }
        //posVisit(v);
    }

    void traverseDFS(int val){
        for(int v = 0; v<numVertex; v++)
            setMark(v, UNVISITED);

        for(int v=0; v<numVertex; v++)
            if(getMark(v) == UNVISITED)
                DFS(val);
    }

    void BFS(int start){
        queue<int> Q;
        Q.push(start);
        setMark(start, VISITED);
        while(Q.size() > 0){
            int v = Q.front();
            Q.pop();
            //previsit(v);
            int w = first(v);
            while(w < numVertex){
                if(getMark(w) == UNVISITED){
                    setMark(w, VISITED);
                    Q.push(w);
                }
                w = next(v, w);
            }
            //posVisit(v);
            cout << v << " ";
        }
    }

    void traverseBFS(int s){
        for(int v=0; v<numVertex; v++)
            setMark(v, UNVISITED);
        
        for(int v=0; v<numVertex; v++){
            if(getMark(v) == UNVISITED)
                BFS(0);
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
    
    int vertex, numOp, v1, v2, start;
    string op;
    cin >> vertex >> numOp;
    Graph gr(vertex);
    for(int i=0; i<numOp; i++){
        cin >> op;
        if(op == "add"){
            cin >> v1 >> v2;
            gr.setEdge(v1, v2, NEW_EDGE);
        }else if(op == "BFS"){
            cin >> start;
            gr.traverseBFS(start);
            cout << "\n";
        }else if(op == "DFS"){
            cin >> start;
            gr.traverseDFS(start);
            cout << "\n";
        }
    }

    return 0;
}
