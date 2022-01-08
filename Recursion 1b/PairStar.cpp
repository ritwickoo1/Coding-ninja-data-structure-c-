#include <iostream>
using namespace std;
// Change in the given string itself. So no need to return or print the changed string.
//aaaa
//a*a*a*a
void pairStar(char input[]) {
    // Write your code here
	if(input[0]=='\0'){
        return;
    }
    pairStar(input+1);
    if(input[0]==input[1]){
        int size;
        for(size =2; input[size]!='\0';size++);
        for(int i = size+1; i>=2; i--){
            input[i] = input[i-1];
        }
        input[1] = '*';
        
    }
}

int main() {
   char input[100];
   cin.getline(input, 100);
   pairStar(input);
   cout << input << endl;
}
