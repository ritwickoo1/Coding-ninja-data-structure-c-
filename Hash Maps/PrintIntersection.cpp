#include <iostream>
using namespace std;

#include<unordered_map>
void printIntersection(int arr1[], int arr2[], int n, int m) {
    // Write your code here
    unordered_map<int,int> map1;
    for(int i = 0; i < n;i++){
        map1[arr1[i]]++;
    }
    for(int j = 0; j < m; j++){
        if(map1[arr2[j]]>0){
            cout<<arr2[j]<<endl;
            map1[arr2[j]]--;
        }
    } 
}
int main() {
    int n;
    cin >> n;

    int* arr1 = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr1[i];
    }

    int m;
    cin >> m;

    int* arr2 = new int[m];

    for (int i = 0; i < m; ++i) {
        cin >> arr2[i];
    }

    printIntersection(arr1, arr2, n, m);

    delete[] arr1;
    delete[] arr2;
}