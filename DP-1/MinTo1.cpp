#include <bits/stdc++.h>
using namespace std;
#include<climits>
int countMinStepsToOne(int n)
{
	//Write your code here
    if(n <= 1){
        return 0;
    }
    int y = INT_MAX,z = INT_MAX;
    int x = countMinStepsToOne(n-1);
    if(n%2==0){
        y = countMinStepsToOne(n/2);
    }
    if(n%3==0){
        z = countMinStepsToOne(n/3);
    }
    int ans = 1+min(x,min(y,z));
    return ans;
}
int main()
{
	int n;
	cin >> n;
	cout << countMinStepsToOne(n);
}