#include <iostream>

using namespace std;
void printAllPossibleCodes(string input,string output){
    if(input.empty()){
        cout<<output<<endl;
        return;
    }
    int num = input[0]-'0';
    char ch = num-1+'a';
    printAllPossibleCodes(input.substr(1),output+ch);
    if(input[1]!='\0'){
        num = num*10 + input[1]-'0';
        ch = num - 1 + 'a';
        if(num >= 10 && num <= 26){
            printAllPossibleCodes(input.substr(2),output+ch);
        }
    }
}
void printAllPossibleCodes(string input){
    string output = "";
    printAllPossibleCodes(input,output);
}
int main(){
    string input;
    cin >> input;

    printAllPossibleCodes(input);
    return 0;
}

