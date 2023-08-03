#include <iostream>
#include <stdlib.h>
#include <queue>

using namespace std;

#define UNVISITED 0
#define VISITED 1
#define MAX 100

struct tripla{
    int antes;
    int atual;
    int wt;

    tripla(int antes, int atual, int wt): antes(antes), atual(atual), wt(wt){}

    bool operator< (const tripla &e) const{
        return wt < e.wt;
    }

    bool operator> (const tripla &e) const {
        return wt > e.wt;
    }
};

vector<vector<tripla>> adj;

class Graph{
private:
    int** matrix;
    int numVertex;
    int numEdge;
    int* mark;
public:
    Graph(int nV, int nE){
        mark = new int[nV];
        matrix = new int*[nV];
        for(int i=0; i<nV; i++){
            matrix[i] = new int[nV];
            for(int j = 0; j<nV; j++)
                matrix[i][j] = 0;
        }
        numVertex = nV;
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
        if(wt<0)
            return;
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

    int weight(int i, int j){
        return matrix[i][j];
    }

    void floyd(){

        int D[numVertex][numVertex];
        for(int i=0; i<numVertex; i++){
            for(int j=0; j<numVertex; j++){
                if(i = j)
                    D[i][j] = 0;
                else if(weight(i, j) != 0)
                    D[i][j] = weight(i, j);
                else
                    D[i][j] = MAX;
            }
        }

        for(int k=0; k<numVertex; k++){
            for(int i=0; i<numVertex; i++){
                for(int j=0; j<numVertex; j++){
                    if(D[i][k] != MAX && D[k][j] != MAX && D[i][j] > D[i][k] + D[k][j])
                        D[i][j] = D[i][k] + D[k][j];
                }
            }
        }


        for(int i=0; i<numVertex; i++){
            for(int j=0; j<numVertex; j++)
                cout << D[i][j] << " ";
            cout << "\n";
        }
    }
  
    void Prim(int D[], int V[]){
        for(int i=0; i<numVertex; i++){
            D[i] = MAX; V[i] = 0;
            setMark(i, UNVISITED);
        }
        priority_queue<tripla, vector<tripla>, greater<tripla> > H;
        H.push(tripla(0,0,0)); D[0] = 0;

        int p, v;
        for(int i=0; i<numVertex; i++){
            do{
                tripla t = H.top();
                p = t.antes; v = t.atual;

                if(H.empty())
                    return;

                H.pop();
            }while(getMark(v) == VISITED);

            setMark(v, VISITED); V[v] = p;
            int w = first(v);
            while(w<numVertex){
                if((getMark(w) != VISITED) && (D[w] > weight(v, w))){
                    D[w] = weight(v, w);
                    H.push(tripla(v, w, D[w]));
                }
                w = next(v, w);
            }
        }

        int sum = 0;
        for(int i=0; i<numVertex; i++)
            sum += D[i];
        cout << sum;
    }

    void printMatrix(){
        for(int i=0; i<numVertex; i++){
            for(int j=0; j<numVertex; j++)
                cout << matrix[i][j] << " ";
            cout << "\n";
        }
    }

};

int main(){

    int nv, ne;
    int v1, v2, wt;
    cin >> nv >> ne;
    Graph be(nv, ne);
    int D[nv]; int V[nv];
    for(int i=0; i<nv; i++){
        cin >> v1 >> v2 >> wt;
        be.setEdge(v1, v2, wt);
    }

    //be.printMatrix();
    be.Prim(D, V);
    //be.floyd();
    return 0;
}