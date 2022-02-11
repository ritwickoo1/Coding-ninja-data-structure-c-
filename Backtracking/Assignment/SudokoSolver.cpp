#include <bits/stdc++.h>
using namespace std;
#define N 9
bool isRowSafe(int grid[N][N],int row,int num){
    for(int i = 0; i < N; i++){
        if(grid[row][i]==num){
            return false;
        }
    }
    return true;
}
bool isColSafe(int grid[N][N],int col,int num){
    for(int i = 0; i < N; i++){
        if(grid[i][col]==num){
            return false;
        }
    }
    return true;
}
bool isBlockSafe(int grid[N][N],int row,int col,int num){
    int rowFactor = row - (row%3);
    int colFactor = col - (col%3);
    for(int i = 0; i < 3; i++){
        for(int j = 0 ; j < 3; j++){
            if(grid[i+rowFactor][j+colFactor]==num){
                return false;
            }
        }
    }
    return true;
}
bool isSafe(int grid[N][N],int row,int col,int num){
    return (isRowSafe(grid,row,num) && isColSafe(grid,col,num) && isBlockSafe(grid,row,col,num));
}
bool findEmptySolution(int grid[N][N],int &row,int &col){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(grid[i][j] == 0){
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}
bool solveSudoko(int grid[N][N]){
    int row,col;
    if(!findEmptySolution(grid,row,col)){
        return true;
    }
    for(int i = 1; i <= N; i++){
        if(isSafe(grid,row,col,i)){
            grid[row][col] = i;
            if(solveSudoko(grid)){
                return true;
            }
            grid[row][col] = 0;
        }
    }
    return false;
}
int main() {
	// your code goes here
	int grid[N][N];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> grid[i][j]; 
        }
    }	
   	if(solveSudoko(grid)){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
    
    
	return 0;
}
