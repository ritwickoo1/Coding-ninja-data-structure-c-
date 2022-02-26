#include <iostream>
#include<queue>
using namespace std;
bool hasPath(int **edges, int v,int v1,int v2, bool *visited){
    if(edges[v1][v2]==1){
        return true;
    }
    visited[v1] = true;
	bool res = false;
	for(int i = 0 ; i < v; i++){
		if(!visited[i] && edges[v1][i]==1)
			res = hasPath(edges,v,i,v2,visited);
		if(res){
			return true;
		}
	}
	return res;
}
int main() {
    // Write your code here
    int v,e;
    cin >> v >> e;
    int **edges = new int*[v];
    for(int i = 0 ; i < v; i++){
        edges[i] = new int[v];
        for(int j = 0; j < v; j++){
            edges[i][j] = 0;
        }
    }
    for(int i = 0; i < e; i++){
            int f,s;
            cin >> f >> s;
            edges[f][s] = 1;
            edges[s][f] = 1;
    }
    int v1,v2;
    cin >> v1 >> v2;
    bool *visited = new bool[v];
    for(int i = 0; i < v; i++){
    	visited[i] = false;
	}
    if(hasPath(edges,v,v1,v2,visited)){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
    for(int i = 0; i < v; i++){
    	delete [] edges[i];
	}
	delete [] edges;
	return 0;
}