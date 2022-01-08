#include <iostream>
using namespace std;
void merge(int *input,int *a,int *b,int size,int n1,int n2){
    int i = 0,j = 0,k=0;
    while(i<n1&&j<n2){
        if(a[i]<b[j]){
            input[k++] = a[i++];
        }else{
            input[k++] = b[j++];
        }
    }
    while(i<n1){
        input[k++] = a[i++];
    }
    while(j<n2){
        input[k++] = b[j++];
    }
}
void mergeSort(int input[], int size){
	// Write your code here
  	if(size<=1){
        return;
    }
    int mid = size/2;
    int a[mid],b[size-mid];
    for(int i = 0; i < mid; i++){
        a[i] = input[i];
    }
    for(int i = mid; i < size; i++){
        b[i-mid] = input[i];
    }
    mergeSort(a,mid);
    mergeSort(b,size-mid);
    merge(input,a,b,size,mid,size-mid);
}

int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}