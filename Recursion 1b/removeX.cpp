#include <iostream>
using namespace std;
// Change in the given string itself. So no need to return or print anything
//xaxb
//ab
void removeX(char input[]) {
    // Write your code here
	if(input[0]=='\0'){
        return;
    }
    if(input[0]!='x')
        removeX(input+1);
    else{
        int i;
        for( i = 0; input[i]!='\0';i++){
            input[i] =input[i+1]; 
        }
        input[i] = '\0';
        removeX(input);
    }
}

int main() {
    char input[100];
    cin.getline(input, 100);
    removeX(input);
    cout << input << endl;
}
