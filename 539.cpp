#include<iostream>
using namespace std;

int maximo=0;

void backtrackingFromNode(int i, bool* usedEdges, int d, int** edges,int m){
    //cout << "Llego a distancia "<<d<<endl;
    if (d>maximo) maximo=d;
    for (int j=0; j<m; j++){
        if (edges[j][0]==i and !usedEdges[j]){
            usedEdges[j]=true;
            backtrackingFromNode(edges[j][1], usedEdges, d+1, edges,m);
            usedEdges[j]=false;
        }else{
            if (edges[j][1]==i and !usedEdges[j]){
                usedEdges[j]=true;
                backtrackingFromNode(edges[j][0], usedEdges, d+1, edges,m);
                usedEdges[j]=false;
            }
        }
    }
}

int main(void){
    while(true){
        int n,m;
        maximo=0;
        cin >> n >> m;
        if (n==0 && m==0) break;
        int** edges = new int*[m];
        for (int i=0; i<m; i++){
            edges[i]=new int[2];
            cin >> edges[i][0] >> edges[i][1];
        }
        for (int i=0; i<n; i++){
            bool* usedEdges = new bool[m];
            for (int j=0; j<m; j++) usedEdges[j]=false;
            int d=0;
            backtrackingFromNode(i, usedEdges, d, edges,m);
            delete usedEdges;
        }
        cout << maximo<<endl;

        for (int i=0; i<m; i++) delete edges[i];
        delete edges;
    }
}