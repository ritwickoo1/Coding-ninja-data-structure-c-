#include<bits/stdc++.h>
using namespace std;
// DP
void fib3_helper(int arr[],int n){
	arr[0] = 0;
	arr[1] = 1;
	for(int i = 2; i < n; i++){
		arr[i] = arr[i-1] + arr[i-2];
	}
}
void fib3(int n){
	int *arr = new int[n];
	memset(arr,-1,n*sizeof(int));
	fib3_helper(arr,n);
	for(int i = 0; i < n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
// Memoization
int fib2_helper(int arr[],int n){
	if(n<=1){
		return n;
	}
	if(arr[n]!=-1){
		return arr[n];
	}
	int a = fib2_helper(arr,n-1);
	int b = fib2_helper(arr,n-2);
	arr[n] = a+b;
	return arr[n];
}
void fib2(int n){
	int *arr = new int[n];
	memset(arr,-1,n*sizeof(int));
	
	for(int i = 0; i < n; i++){
		cout<<fib2_helper(arr,i)<<" ";
	}
	cout<<endl;
}
// Normal recursion
int fib(int n){
	if(n<=1){
		return n;
	}
	return fib(n-1)+fib(n-2);
}
int main(){
	for(int i = 0; i < 5; i++){
		cout<<fib(i)<<" ";
	}
	cout<<endl;
	fib2(8);	
	fib3(10);
	return 0;
}