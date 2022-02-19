#include <bits/stdc++.h>
using namespace std;
int minCostPath_Memo(int **input, int i,int j, int m, int n,int **output)
{
	//Write your code here
    if(i == m-1 && j == n-1){
       return input[i][j];
    }
    if(i >= m || j >= n){
    	return INT_MAX;
	}
	if(output[i][j]!=-1){
		return output[i][j];
	}
	
    int a = minCostPath_Memo(input,i+1,j,m,n,output);
	int	b = minCostPath_Memo(input,i,j+1,m,n,output);
    int c = minCostPath_Memo(input,i+1,j+1,m,n,output);
 	int sum = input[i][j] + min(min(a,b),c);
	output[i][j] = sum;
	return sum;
}
/*
int minCostPath(int **input, int i,int j, int m, int n,int sum)
{
	//Write your code here
    if(i == m-1 && j == n-1){
       return input[i][j];
    }
    if(i >= m || j >= n){
    	return INT_MAX;
	}
    int a = minCostPath(input,i+1,j,m,n,sum);
	int	b = minCostPath(input,i,j+1,m,n,sum);
    int c = minCostPath(input,i+1,j+1,m,n,sum);
 	sum += input[i][j] + min(min(a,b),c);
	return sum;
}*/
int minCostPath(int **input, int m, int n)
{
	//Write your code here
    int **output=new int*[m];
    for(int i = 0; i < m; i++){
    	output[i] = new int[n];
	}
    for(int i = 0; i < m; i++){
        memset(output[i],-1,n*sizeof(int));
    }
    return minCostPath_Memo(input,0,0,m,n,output);
}
int minCostDP(int **input,int n,int m){
	int **output = new int*[n];
	for(int i = 0; i < n; i++){
		output[i] = new int[m];
	}
	output[n-1][m-1] = input[n-1][m-1];
	// fill the last row
	for(int j = m-2;j>=0; j--){
		output[n-1][j] = input[n-1][j] + output[n-1][j+1]; 
	}
	// fill the last column
	for(int i = n-2;i>=0; i--){
		output[i][m-1] = input[i][m-1] + output[i+1][m-1]; 
	}
	// fill remaining columns
	for(int i = n-2; i >= 0; i--){
		for(int j = m-2; j >= 0; j--){
			output[i][j] = input[i][j] + min(output[i][j+1],min(output[i+1][j],output[i+1][j+1]));
		}
	}
	return output[0][0];
}
int main()
{
	int **arr, n, m;
	cin >> n >> m;
	arr = new int *[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	cout << minCostPath(arr, n, m) << endl;
	cout<<minCostDP(arr,n,m)<<endl;
}