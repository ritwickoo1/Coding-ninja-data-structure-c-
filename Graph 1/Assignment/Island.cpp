#include <iostream>
using namespace std;
/*
An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group . Given V islands (numbered from 1 to V) and E connections or edges between islands. Can you count the number of connected groups of islands.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b. 
Output Format :
Print the count the number of connected groups of islands
Constraints :
0 <= V <= 1000
0 <= E <= (V * (V-1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
Time Limit: 1 second
Sample Input 1:
5 8
0 1
0 4
1 2
2 0
2 4
3 0
3 2
4 3
Sample Output 1:
1  
*/
void countComponentsDFS(int **graph,int n,int sv,bool *visited,int &count){
    visited[sv] = true;
	for(int i = 0; i < n; i++){
        if(!visited[i] && graph[sv][i]){
            countComponentsDFS(graph,n,i,visited,count);
        }
    }
}
int main() {
    int n,e;
    cin >> n >> e;

    int **graph = new int*[n];
    for(int i = 0;i < n; i++)
    {
        graph[i] = new int[n];
        for(int j = 0; j < n; j++)
            graph[i][j] = 0;
    }

    for(int i = 0; i < e; i++)
    {
        int f,s;
        cin >> f >> s;
        graph[f][s] = 1;
        graph[s][f] = 1;
    }

    bool *visited = new bool[n];
    for(int i= 0 ; i < n; i++){
        visited[i] = false;
    }
    int count = 0;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
        	countComponentsDFS(graph,n,i,visited,count);   
            count++;
        	cout<<endl;
        }
    }
    cout<<count<<endl;
	for(int i = 0; i < n; i++){
        delete [] graph[i];
    }
    delete [] graph;
    return 0;
}