//a. The string begins with an 'a'
//b. Each 'a' is followed by nothing or an 'a' or "bb"
//c. Each "bb" is followed by nothing or an 'a'

#include <iostream>
using namespace std;
bool checkrule(char input[]){
    if(input[0]=='\0'){
        return true;
    }
    bool sol;
    if(input[0]=='a'&&(input[1]=='\0'||input[1]=='a'))
        sol = checkrule(input+1);
    else if(input[0] == 'a' &&  (input[1]=='b'&& input[2]=='b'))
        sol = checkrule(input+1);
    else if(input[0]=='b' && input[1]=='b' && (input[2]=='a'||input[2]=='\0'))
        sol = checkrule(input+2);
    else
        return false;
    return sol;
}
bool checkAB(char input[]) {
	// Write your code here
	if(input[0]=='\0'){
    	return true;    
    }else if(input[0]!='a'){
        return false;
    }
    return checkrule(input);
}




int main() {
    char input[100];
    bool ans;
    cin >> input;
    ans=checkAB(input);
    if(ans)
        cout<< "true" << endl;
    else
        cout<< "false" << endl;
}
