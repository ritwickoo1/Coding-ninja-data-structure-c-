#include <iostream>
using namespace std;
#include<algorithm>
int maximumProfit(int budget[], int n) {
    // Write your code here
	int max = 0;
    sort(budget,budget+n);
    for(int i = 0; i < n; i++){
        int x= budget[i];
		int maxProfit = x*(n-i);
        if(maxProfit > max){
            max = maxProfit;
        }
    }
    return max;
}

int main() {
    int n ,*input,i,*cost;
    cin>>n;
    input = new int[n];
    for(i = 0;i < n;i++)
        cin>>input[i];
    
    cout << maximumProfit(input, n) << endl;
    
}
