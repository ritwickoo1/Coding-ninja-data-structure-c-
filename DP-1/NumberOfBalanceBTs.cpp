#include <bits/stdc++.h>
using namespace std;
int balancedBTs(int n) {
    // Write your code here
    if(n<=1){
        return 1;
    }
    int x = balancedBTs(n-1);
    int y = balancedBTs(n-2);
    int num = (int)(pow(10,9))+7;
    int temp1 = (int) (((long)(x)*x)%num);
    int temp2 = (int) ((2*(long)(x)*y)%num);
    return (int) ((temp1+temp2)%num);
}
int main() {
    int n;
    cin >> n;
    cout << balancedBTs(n);
}