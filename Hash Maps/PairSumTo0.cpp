#include <iostream>
using namespace std;

#include<unordered_map>
int pairSum(int *arr, int n) {
	// Write your code here
    unordered_map<int,int> freqMap;
    int count = 0;
    for(int i = 0; i < n; i++){
        if(freqMap.count(-arr[i])>0){
            count+=freqMap[-arr[i]];
        }
        freqMap[arr[i]]++;
    }
    return count;
}
int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << pairSum(arr, n);

    delete[] arr;
}