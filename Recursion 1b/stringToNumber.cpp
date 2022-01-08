#include <iostream>
using namespace std;
//00001231
//1231
int stringToNumber(char input[]) {
    // Write your code here
	if(input[0]=='\0'){
        return 0;
    }
    int ans = stringToNumber(input+1);
	int power = 1;
    for(int i = 1; input[i]!='\0';i++)
        power*=10;
    int digit = input[0]-'0';
    return digit*power+ans;
}



int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}
