#include <iostream>
#include <string>
using namespace std;
#include<stack>
int countBracketReversals(string input) {
	// Write your code here
    if(input.size()%2) return -1;
    stack<char>s;
	for(int i = 0; i < input.size(); i++){
        if(s.empty() && input[i]=='}'){
            s.push(input[i]);
        }else if(input[i]=='}' && s.top()=='{' && !s.empty()){
            s.pop();
        }else{
            s.push(input[i]);
        }
        
    }
  // if(s.top()=='{') cout<<"true"<<endl;
    if(s.empty()) return 0;
    int count = 0;
    while(!s.empty()){
        char c1 = s.top();
        //cout<<c1<<endl;
        s.pop();
        char c2 = s.top();
        //cout<<c2<<endl;
        s.pop();
        if(c1 == c2){
            count += 1;
        }else{
            count+=2;
        }
    }
    return count;
}

int main() {
    string input;
    cin >> input;
    cout << countBracketReversals(input);
}