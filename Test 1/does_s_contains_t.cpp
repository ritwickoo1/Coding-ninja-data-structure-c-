#include<iostream>
using namespace std;
bool checksequenece(char large[] , char*small) {
	if(small[0]=='\0'){
        return true;
    }
    if(large[0]=='\0'){
        return false;
    }
    bool sol;
    if(large[0] == small[0]){
        sol = checksequenece(large+1,small+1); 
    }else{
        sol = checksequenece(large+1,small);
    }
    return sol;
}
//abchjsgsuohhdhyrikkknddg
//coding
// result:- true
int main()
{
	char large[10000];
	char small[10000];
	cin>>large;
	cin>>small;
	bool x=checksequenece(large , small);

	if(x)
		cout<<"true";
	else
		cout<<"false";

}
