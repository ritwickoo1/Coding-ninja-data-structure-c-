#include<bits/stdc++.h>
using namespace std;
void printSolution(int **solution,int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout<<solution[i][j]<<" ";
		}
	}
	cout<<endl;
}
void mazeHelper(int **maze,int **solution,int n,int x,int y){
    if(x == n-1 && y == n-1){
    	solution[x][y] = 1;
        printSolution(solution,n);
        solution[x][y] = 0;
        return;
    }
    if(x >= n || x < 0|| y>=n || y < 0|| solution[x][y]==1|| maze[x][y]==0)
        return;
    solution[x][y] = 1;
    mazeHelper(maze,solution,n,x-1,y);
    mazeHelper(maze,solution,n,x+1,y);
    mazeHelper(maze,solution,n,x,y-1);
    mazeHelper(maze,solution,n,x,y+1);
    solution[x][y] = 0;
}
void ratInMax(int **maze,int n){
    int ** solution = new int*[n];
    for(int i = 0; i < n; i++){
        solution[i] = new int[n];
    }
    for(int i = 0; i < n; i++){
        memset(solution[i],0,n*sizeof(int));
    }
	//memset(solution,0,n*n*sizeof(int));
    mazeHelper(maze,solution,n,0,0);
}
int main() {

	// Write your code here
    int n;
    cin >> n;
    int **arr = new int*[n];
    for(int i = 0; i < n; i++){
        arr[i] = new int[n];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0 ; j < n; j++){
          	cin >> arr[i][j];  
        }
    }
	ratInMax(arr,n);    
    
	return 0;
}