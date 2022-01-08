#include <iostream>
#include <string>
using namespace std;

#include <iostream>
#include <string>
using namespace std;
void printPermutations(string input,string output){
    if(input.empty()){
        cout<<output<<endl;
        return;
    }
    for(int i = 0; i <= output.size(); i++){
        printPermutations(input.substr(1),output.substr(0,i)+input[0]+output.substr(i));
    }
    
}
void printPermutations(string input){

    	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
    string output = "";
    printPermutations(input,output);
}

int main() {
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
}