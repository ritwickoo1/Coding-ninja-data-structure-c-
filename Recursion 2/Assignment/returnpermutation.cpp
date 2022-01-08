#include <string>
using namespace std;

int returnPermutations(string input, string output[]){
   	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
    if(input.empty()){
        output[0] = "";
        return 1;
    }
    string temp[1000];
    int smalloutput = returnPermutations(input.substr(1),temp);
    int k = 0;
    for(int i = 0; i < smalloutput; i++){
        for(int j = 0; j <= temp[i].length();j++){
            output[k++] = temp[i].substr(0,j) + input[0]+temp[i].substr(j); 
        }
    }
    return k;
}
