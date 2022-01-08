#include <iostream>
using namespace std;
bool isPal(char input[],int s,int e){
    if(s==e){
        return true;
    }
    if(input[s]!=input[e]){
        return false;
    }
    if(s < e+1){
        return isPal(input,s+1,e-1);
    }
    return true;
}
bool checkPalindrome(char input[]) {
    // Write your code here
	int  n = 0;
    for(int i = 0; input[i]!='\0';i++){
        n++;
    }
    if(n == 0){
        return true;
    }
    return isPal(input,0,n-1);
}
int main() {
    char input[50];
    cin >> input;
    
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
