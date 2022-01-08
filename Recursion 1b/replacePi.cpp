#include <iostream>
using namespace std;
// Change in the given string itself. So no need to return or print anything
void replacePi(char input[]) {
	// Write your code here
	if(input[0]=='\0'){
        return;
    }
    replacePi(input+1);
    if(input[0]=='p'&& input[1]=='i'){
        input[0] = '3';
        input[1] = '.';
        int size = 0;
        for(int i = 0; input[i]!='\0';i++){
            size++;
        }
        for(int i = size+2; i > 1; i--){
            input[i] = input[i-2];
        }
        input[2] = '1';
        input[3] = '4';
    }
    
}

int main() {
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}
// xpix
//x3.14x