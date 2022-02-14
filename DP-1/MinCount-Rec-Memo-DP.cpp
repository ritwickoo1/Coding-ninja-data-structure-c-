#include <bits/stdc++.h>

using namespace std;

int minCount(int n)
{
	//Write your code here
	if(sqrt(n)-floor(sqrt(n))==0){
		return 1;
	}
	if(n <= 3){
		return n;
	}
	int ans = n;
	for(int i = 1; i*i <= n; i++){
		ans = min(ans,1+minCount(n-i*i));
	}
	return ans;
}
int main()
{
	int n;
	cin >> n;
	cout << minCount(n);
}