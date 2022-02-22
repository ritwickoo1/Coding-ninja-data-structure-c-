#include <iostream>
#include <string>
using namespace std;
/*
Gary has two string S and V. Now, Gary wants to know the length shortest subsequence in S, which is not a subsequence in V.
Note: The input data will be such that there will always be a solution.
Input Format :
The first line of input contains a string, that denotes the value of S. The following line contains a string, that denotes the value of V.
Output Format :
Length of shortest subsequence in S such that it is not a subsequence in V
Constraints:
1 <= |S| <= 1000 (|x| implies the length of the string x)
1 <= |V| <= 1000 
Time Limit: 1 second
Sample Input 1:
babab
babba
Sample Output 1:
3
Explanation:
"aab" is the shortest subsequence which is present in S and absent in V. 
*/
#define MAX 1005
int solve(string s, string v) {
    // Write your code here
    int m = s.size(), n = v.size();
    int dp[m+1][n+1];
    // fill column
    for(int i = 0; i <= m; i++){
        dp[i][0] = 1;
    }
    // fill row
    for(int j = 0; j <= n; j++){
        dp[0][j] = MAX;
    }
    for(int i = 1; i <=m; i++){
        for(int j = 1; j <= n; j++){
            char ch = s[i-1];
            int k;
            for(k = j-1; k >= 0; k--){
                if(ch == v[k])
                    break;
            }
            if(k==-1){
                dp[i][j] = 1;
            }else
               dp[i][j] = min(dp[i-1][j], dp[i-1][k] + 1);
        }
    }
    int ans = dp[m][n];
    if(ans >= MAX){
        ans = -1;
    }
    return ans;
}
int main() {
    string s, v;
    cin >> s >> v;
    cout << solve(s, v);
}