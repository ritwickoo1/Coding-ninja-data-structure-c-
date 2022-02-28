#include <iostream>
#include <limits>
using namespace std;
int findMinVertex(int *distance,bool *visited,int v){
    int minVertex = -1;
    for(int i = 0; i < v; i++){
        if(!visited[i] && (minVertex==-1 || distance[i] < distance[minVertex])){
            minVertex = i;
        }
    }
    return minVertex;
}
void dijkstra(int **edges,int v){
    bool *visited = new bool[v];
    int  *distance = new int[v];
    for(int i = 0; i < v; i++){
        visited[i] = false;
        distance[i] = INT_MAX;
    }
    distance[0] = 0;
    for(int i = 0; i < v; i++){
        int minVertex = findMinVertex(distance,visited,v);
        visited[minVertex] = true;
        for(int j = 0; j < v; j++){
            if(edges[minVertex][j]!=0 && !visited[j]){
                int dist = distance[minVertex]+edges[minVertex][j];
                if(dist < distance[j]){
                    distance[j] = dist;
                }
            }
        }
    }
    for(int i = 0; i < v; i++){
        cout<<i<<" "<<distance[i]<<endl;
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
    dijkstra(edges,v);
    return 0;
}