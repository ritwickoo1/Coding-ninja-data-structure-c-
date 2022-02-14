#include <bits/stdc++.h>
using namespace std;
int countStepsToOne(int n,int *arr){
	if(n <= 1){
		return 0;
	}
	if(arr[n]!=-1){
		return 1+arr[n];
	}
	int x = countStepsToOne(n-1,arr);
	int y , z ;
	y = z = INT_MAX;
	if(n%2==0){
		y = countStepsToOne(n/2,arr);
	}
	if(n%3==0){
		z = countStepsToOne(n/3,arr);
	}
	arr[n] = min(x,min(y,z));
	return 1+arr[n];
}
int countStepsToOne(int n)
{
    int *arr = new int[n+1];
    memset(arr,-1,(n+1)*sizeof(int));
    return countStepsToOne(n,arr);
}
int main()
{
	int n;
	cin >> n;
	cout << countStepsToOne(n);
}