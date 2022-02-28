#include <iostream>
#include<limits.h>
using namespace std;
int findMinVertex(bool *visited,int v, int *weight){
    int minVertex = -1;
    for(int i = 0; i < v; i++){
        if(!visited[i] && (minVertex == -1 || weight[i] < weight[minVertex])){
            minVertex = i;
        }
    }
    return minVertex;
}
void prims(int **edges,int v){
    bool *visited = new bool[v];
    int *parent = new int[v];
    int *weight = new int[v];
    for(int i = 0; i < v; i++){
        visited[i] = false;
    	weight[i] = INT_MAX;
    }
    parent[0] = -1;
    weight[0] = 0;
    for(int i = 0; i < v; i++){
        int minVertex = findMinVertex(visited,v,weight);
        visited[minVertex] = true;
    	for(int j = 0; j < v; j++){
            if(edges[minVertex][j] != 0 && !visited[j]){
                if(edges[minVertex][j] < weight[j]){
                    weight[j] = edges[minVertex][j];
                    parent[j] = minVertex; 
                }
            }
        }
    }
    for(int i = 1; i < v; i++){
        if(parent[i] < i){
            cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
        }else{
            cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
        }
    }
}
int main() {
    // Write your code here
    int v,e;
    cin >> v >> e;
    int **edges = new int*[v];
    for(int i = 0; i < v; i++){
    	edges[i] = new int[v];
        for(int j = 0; j < v; j++){
            edges[i][j] = 0;
        }
    }
    for(int i = 0; i < e; i++){
        int f,s,weight;
        cin >> f >> s >> weight;
        edges[f][s] = weight;
        edges[s][f] = weight;
    }
	prims(edges,v);
    for(int i = 0 ; i < v; i++){
        delete [] edges[i];
    }
    delete [] edges;
}