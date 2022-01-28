#include <iostream>
using namespace std;

#include<unordered_map>
#include<unordered_map>
int highestFrequency(int arr[], int n) {
    // Write your code here
    unordered_map<int,int> freqMap;
    for(int i = 0; i < n; i++)
       freqMap[arr[i]]++;
    int max = 0,highest;
    for(int i = 0; i < n; i++){
        if(max < freqMap[arr[i]]){
            max = freqMap[arr[i]];
            highest = arr[i];
        }
    }
    return highest;
}
int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << highestFrequency(arr, n);

    delete[] arr;
}