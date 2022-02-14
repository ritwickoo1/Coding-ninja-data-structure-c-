#include <iostream>
using namespace std;
#include<cmath>
//memoization
int balancedBTs(int*arr,int n) {
    // Write your code here
	if(n <= 1){
        return 1;
    }
    if(arr[n]!=0){
        return arr[n];
    }
    int a = balancedBTs(arr,n-1);
    int b = balancedBTs(arr,n-2);
    int mod = (int)(pow(10,9)) + 7;
    int temp1 = (int)(((long)(a)*a)%mod);
    int temp2 = (int)((2*(long)(a)*b)%mod);
    arr[n] = (temp1+temp2)%mod;
    return arr[n];
}
int balancedBTs(int n) {
    // Write your code here
	int *arr = new int[n+1];
    memset(arr,0,(n+1)*sizeof(int));
    return balancedBTs(arr,n);
    
}
int main() {
    int n;
    cin >> n;
    cout << balancedBTs(n);
}