#include <iostream>

using namespace std;

int getCodes(string input, string output[10000]) {
    /*
    You are given the input text and output string array. Find all possible codes and store in the output string array. Donât print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
    */
    if(input.empty()){
        output[0]="";
        return 1;
    }
    int smalloutput1 = getCodes(input.substr(1),output);
    int num = input[0]-'0';
    char ch =  'a'+num  - 1;
    for(int i = 0; i < smalloutput1;i++){
        output[i] = ch+output[i];
    }
    int smalloutput2 = 0;
    if(input[1]!='\0'){
        num = num*10 + input[1] - '0';
        ch = num - 1 + 'a';
        if(num >=10 && num <=26){
            smalloutput2 = getCodes(input.substr(2),output+smalloutput1);    
            for(int i = 0; i < smalloutput2;i++){
                output[i+smalloutput1] = ch+output[i+smalloutput1];
            }   
         
        }
    }
	return smalloutput1+smalloutput2;
}


int main(){
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for(int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}
