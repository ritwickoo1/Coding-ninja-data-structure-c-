#include <iostream>
#include<string>
using namespace std;
int subs(string input,string output[]){
    if(input.empty()){
        output[0] = "";
        return 1;
    }
    int smallsize = subs(input.substr(1),output);
    for(int i = 0;i < smallsize; i++){
        output[i+smallsize] = input[0]+output[i];
    }
    return 2*smallsize;
}
int main()
{
    string input;
    cin >>  input;
    string *output = new string[1000];
    int n = subs(input,output);
    for(int i = 0; i < n; i++){
        cout<<output[i]<<endl;
    }
    return 0;
}
