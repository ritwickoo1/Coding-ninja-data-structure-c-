#include <iostream>
using namespace std;
void printSubsetsOfArray(int input[],int size,int output[],int m){
    if(size==0){
        for(int i = 0; i < m; i++){
            cout<<output[i]<<" ";
        }
        cout<<endl;
        return;
    }
    printSubsetsOfArray(input+1,size-1,output,m);
    int *newoutput = new int[m+1];
    int i = 0;
    for(; i < m;i++){
        newoutput[i] = output[i];
    }
    newoutput[i] = input[0];
    printSubsetsOfArray(input+1,size-1,newoutput,m+1);
}
void printSubsetsOfArray(int input[], int size) {
	// Write your code here 
    int output[size];
    int m = 0 ;
    printSubsetsOfArray(input,size,output,m);
}

int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
  	cin >> input[i];
  printSubsetsOfArray(input, length);
}
