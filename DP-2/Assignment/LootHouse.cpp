/*
A thief wants to loot houses. He knows the amount 
of money in each house. He cannot loot two consecutive 
houses. Find the maximum amount of money he can loot.

Input format :
The first line of input contains an integer 
value of 'n'. It is the total number of houses.

The second line of input contains 'n' integer 
values separated by a single space denoting 
the amount of money each house has.

Output format :
Print the the maximum money that can be looted.
Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec
Sample Input 1 :
6
5 5 10 100 10 5
Sample Output 1 :
110
Sample Input 2 :
6
10 2 30 20 3 50
Sample Output 2 :
90
Explanation of Sample Output 2 :
Looting first, third, and the last houses([10 + 30 + 50]) 
will result in the maximum loot, and all the 
other possible combinations would result in less than 90.
*/
#include <iostream>
using namespace std;
// DP
int maxMoneyLooted(int *arr, int n)
{
	//Write your code here
	int *output = new int[n+1];
    output[0] = arr[0];
    output[1] = max(arr[0],arr[1]);
    for(int i = 2; i <= n; i++){
        output[i] = max(arr[i]+output[i-2],output[i-1]);
    }
    return output[n-1];
}
/*Memo
int maxMoneyLootedHelper(int *arr,int n,int *output){
    if(n<=0){
        return 0;
    }
    if(output[n]!=-1){
        return output[n];
    }
    int ans = max(arr[0]+maxMoneyLootedHelper(arr+2,n-2,output),maxMoneyLootedHelper(arr+1,n-1,output));
    output[n] = ans;
    return output[n];
}
int maxMoneyLooted(int *arr, int n)
{
	//Write your code here
	int *output = new int[n+1];
    memset(output,-1,(n+1)*sizeof(int));
    return maxMoneyLootedHelper(arr,n,output);
    
}*/
/* Brute Force (Recursive)
int maxMoneyLooted(int *arr, int n)
{
	//Write your code here
	if(n<=0){
		return 0;
	}
    return max(arr[0]+maxMoneyLooted(arr+2,n-2),maxMoneyLooted(arr+1,n-1));
    
}*/
int main()
{
	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cout << maxMoneyLooted(arr, n);

	delete[] arr;
}