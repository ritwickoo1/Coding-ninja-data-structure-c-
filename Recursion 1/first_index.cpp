#include<iostream>
using namespace std;
int firstIndex(int input[], int size, int x) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
	if(size==0){
        return -1;
    }   
    if(input[0]==x){
    	return 0;
    }else{
        int index = firstIndex(input+1,size-1,x);
        if(index!=-1)
            return index+1;
        else 
            return -1;
    }
     
}


int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    
    cin >> x;
    
    cout << firstIndex(input, n, x) << endl;

}


