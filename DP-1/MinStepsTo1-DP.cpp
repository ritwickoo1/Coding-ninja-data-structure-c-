#include <bits/stdc++.h>
using namespace std;
int countStepsToOne(int n)
{
    int arr[n+1];
    arr[1] = 0;
    arr[2] = arr[3] = 1;
	int b,c;
    for(int i = 4; i <= n; i++){
        b = c = n;
        if(i%2==0) b = arr[i/2];
        if(i%3==0) c = arr[i/3];
        arr[i] = 1 + min(arr[i-1],min(b,c));
    }
    return arr[n];
}
int main()
{
	int n;
	cin >> n;
	cout << countStepsToOne(n);
}