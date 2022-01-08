#include <iostream>
#include <string>

using namespace std;

string key[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void printKeypad(int num,string str){
    if(num == 0){
        cout<<str<<endl;
        return;
    }
    int rem = num%10;
    for(int i = 0; i < key[rem].size();i++){
        printKeypad(num/10,key[rem][i]+str);
    }
}
void printKeypad(int num){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
    string output = "";
    printKeypad(num,output);
}

int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}
