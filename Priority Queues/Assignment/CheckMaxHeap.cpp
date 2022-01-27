#include <iostream>
using namespace std;

bool isMaxHeap(int arr[], int n) {
    // Write your code here
	for(int i = 0; i <= n/2-1; i++){
		int parentIndex = i;
		int leftChildIndex = 2*parentIndex+1;
		int rightChildIndex = 2*parentIndex+1;
		if(leftChildIndex < n && arr[parentIndex] < arr[leftChildIndex]){
			return false;
		}
		if(rightChildIndex < n && arr[parentIndex] < arr[rightChildIndex]){
			return false;
		}
	}	
	return true;
}
int main() {
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << (isMaxHeap(arr, n) ? "true\n" : "false\n");

    delete[] arr;
}