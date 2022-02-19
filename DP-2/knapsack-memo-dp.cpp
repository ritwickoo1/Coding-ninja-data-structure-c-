/*
A thief robbing a store can carry a maximal weight of W into his knapsack. There are N items, and i-th item weigh 'Wi' and the value being 'Vi.' What would be the maximum value V, that the thief can steal?
Input Format :
The first line of the input contains an integer value N, which denotes the total number of items.

The second line of input contains the N number of weights separated by a single space.

The third line of input contains the N number of values separated by a single space.

The fourth line of the input contains an integer value W, which denotes the maximum weight the thief can steal.
Output Format :
Print the maximum value of V that the thief can steal.
Constraints :
1 <= N <= 20
1<= Wi <= 100
1 <= Vi <= 100

Time Limit: 1 sec
Sample Input 1 :
  
Sample Output 1 :
13
Sample Input 2 :
5
12 7 11 8 9
24 13 23 15 16
26
Sample Output 2 :
51
*/
#include <cstring>
#include <iostream>
using namespace std;
// DP Solution
int knapsack(int* weight, int* value, int n, int maxWeight) {
	// Write your code here
    int **output = new int*[n+1];
    for(int i = 0; i <= n; i++){
        output[i] = new int[maxWeight+1];
    }
    // fill the row
    for(int j = 0; j <= maxWeight; j++){
    	output[0][j] = 0; 
	}
	// fill the column
    for(int i = 0; i <= n; i++){
    	output[i][0] = 0; 
	}
	// fill the remaining columns
	for(int i = 1; i <=n; i++){
		for(int j = 1; j <= maxWeight; j++){
			if(weight[i-1]>j){
				output[i][j] = output[i-1][j];
			}else{
				int x = output[i-1][j];
				int y = output[i-1][j-weight[i-1]]+value[i-1];
				output[i][j] = max(x,y);
			}
			
		}
	}    
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= maxWeight; j++){
			cout<<output[i][j]<<" ";
		}
		cout<<endl;
	}
	return output[n][maxWeight];
}
/* Memo
int knapsackMemo(int* weight, int* value, int n, int maxWeight,int **output){
    if(n==0||maxWeight==0){
        return 0;
    }
    if(output[n][maxWeight]!=-1){
        return output[n][maxWeight];
    }else{
        if(weight[n-1] > maxWeight){
            output[n][maxWeight] = knapsackMemo(weight,value,n-1,maxWeight,output);
        }else{
            int x = knapsackMemo(weight,value,n-1,maxWeight-weight[n-1],output)+value[n-1];
            int y = knapsackMemo(weight,value,n-1,maxWeight,output);
            output[n][maxWeight] = max(x,y);
        }
    }
    return output[n][maxWeight];
}
int knapsack(int* weight, int* value, int n, int maxWeight) {
	// Write your code here
    int **output = new int*[n+1];
    for(int i = 0; i <= n; i++){
        output[i] = new int[maxWeight+1];
    }
    for(int i = 0; i <= n; i++)
    	memset(output[i],-1,(maxWeight+1)*sizeof(int));
    return knapsackMemo(weight,value,n,maxWeight,output);
}
*/
int main() {
    int n;
    cin >> n;
    int* wt = new int[n];
    int* val = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    for (int j = 0; j < n; j++) {
        cin >> val[j];
    }

    int w;
    cin >> w;

    cout << knapsack(wt, val, n, w) << "\n";

    delete[] wt;
    delete[] val;
}