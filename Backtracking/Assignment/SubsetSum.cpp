#include<bits/stdc++.h>
using namespace std;
void numOfSubsets(int *arr,int n,int targ,int &count,int i,int sum){
	if(i==n){
		if(sum == targ){
			count++;
		}
		return;
	}
	numOfSubsets(arr,n,targ,count,i+1,sum+arr[i]);
	numOfSubsets(arr,n,targ,count,i+1,sum);
}
int main(){
    
    // write your code here
    int t;
    cin >> t;
    while(t--){
        int n,targ;
        cin >> n >> targ;
        int * arr = new int[n];
        for(int i = 0; i < n; i++){
        	cin >> arr[i];
		}
		int count = 0;
		numOfSubsets(arr,n,targ,count,0,0);
    	cout<<count<<endl;
	}
    return 0;
}