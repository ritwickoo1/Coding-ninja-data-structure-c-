#include <bits/stdc++.h>
using namespace std;
/*
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using DFS and print the first path that you encountered.
Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
3. Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
4. Save the input graph in Adjacency Matrix.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex 'a' and 'b'.
The following line contain two integers, that denote the value of v1 and v2.
Output Format :
Print the path from v1 to v2 in reverse order.
Constraints :
2 <= V <= 1000
1 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
0 <= v1 <= 2^31 - 1
0 <= v2 <= 2^31 - 1
Time Limit: 1 second
Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
3 0 1
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :
*/
vector<int>* getPathBFS(int **edges, int v,int v1,int v2){
    if(v1==v2){
        vector<int> *path = new vector<int>;
        path->push_back(v1);
        return path;
    }
    bool *visited = new bool[v];
    for(int i = 0; i < v; i++){
    	visited[i] = false;
	}
    queue<int> pendingEdges;
    pendingEdges.push(v1);
    visited[v1] = true;
    unordered_map<int,int> map;
    bool done = false;
    while(!pendingEdges.empty() && !done){
        int currentVertex = pendingEdges.front();
        pendingEdges.pop();
        for(int i = 0; i < v; i++){
            if(edges[currentVertex][i] && !visited[i]){
                map[i] = currentVertex;
                pendingEdges.push(i);
                visited[i] = true;
                if(i==v2){
                	done = true;
                	break;
				}
            }
        }
    }
    delete [] visited;
    if(!done){
    	return NULL;
	}else{
	
	    vector<int> *path = new vector<int>;
	    path->push_back(v2);
	    int current = v2;
	    while(current!=v1){
	    	current = map[current];
	    	path->push_back(current);
		}
	    return path;
	}
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
    vector<int>* pathBFS = getPathBFS(edges,v,v1,v2);
    if(pathBFS!=NULL)
    for(int i = 0; i < pathBFS->size(); i++){
        cout<<pathBFS->at(i)<<" ";
    }
    delete pathBFS;
    for(int i = 0; i < v; i++){
    	delete [] edges[i];
	}
	delete [] edges;
	return 0;
}