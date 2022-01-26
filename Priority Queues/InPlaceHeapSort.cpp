#include <iostream>

void heapSort(int arr[], int n) {
	for(int i = 1; i < n; i++){
		int childIndex = i;
		while(childIndex > 0){
			int parentIndex = (childIndex-1)/2;
			if(arr[parentIndex] > arr[childIndex]){
				int temp = arr[parentIndex];
				arr[parentIndex] = arr[childIndex];
				arr[childIndex] = temp;
			}else{
				break;
			}
			childIndex = parentIndex;
		}
	}
	int size = n;
	while(size > 1){
		int temp = arr[0];
		arr[0] = arr[size-1];
		arr[size-1] = temp;
		size--;
		int parentIndex = 0;
		int leftChildIndex = 2*parentIndex+1;
		int rightChildIndex = 2*parentIndex+2;
		while(leftChildIndex < size){
			int minIndex = parentIndex;
			if(arr[minIndex] > arr[leftChildIndex]){
				minIndex = leftChildIndex;
			}
			if(arr[minIndex] > arr[rightChildIndex] && rightChildIndex < size){
				minIndex = rightChildIndex;
			}
			if(minIndex == parentIndex) break;
			int temp = arr[minIndex];
			arr[minIndex] = arr[parentIndex];
			arr[parentIndex] = temp;
			
			parentIndex = minIndex;
			leftChildIndex = 2*parentIndex+1;
			rightChildIndex = 2*parentIndex+2;
		} 
	}
	
}
using namespace std;

int main() {
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    } 

    heapSort(input, size);

    for (int i = 0; i < size; i++) {
        cout << input[i] << " ";
    } 

    delete[] input;
}