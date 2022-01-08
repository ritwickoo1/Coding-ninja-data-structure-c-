#include<iostream>
using namespace std;

void swap(int *a,int *b ){
    int c = *a;
    *a = *b;
    *b = c;
}
int partition(int input[],int start,int end){

    int pivot = input[start];
    int i = start+1;
    for(int j = start+1;j <= end; j++){
        if(pivot > input[j]){
            swap(&input[i],&input[j]);
            i++;
        }
    }
    swap(&input[start],&input[i-1]);
    return (i-1);
}
void quickSort(int input[], int start, int end){
        // your code goes here 
    if(start >= end){
        return;
    }
    int part = partition(input,start,end);
    quickSort(input,start,part);
    quickSort(input,part+1,end);
}
void quickSort(int input[], int size) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Change in the given array itself.
     Taking input and printing output is handled automatically.
  */
    quickSort(input, 0, size - 1);

}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}


