#include <iostream>
using namespace std;
#include<queue>

void findMedian(int *arr, int n)
{
    // Write your code here
    priority_queue<int,vector<int>,greater<int>> pqMin;
    priority_queue<int> pqMax;
    for(int i = 0; i < n; i++){
        if(pqMin.empty() && pqMax.empty()){
            pqMax.push(arr[i]);
            cout<<pqMax.top()<<" ";
        }else if(pqMax.top() > arr[i]){
            pqMax.push(arr[i]);
            if(pqMax.size()-pqMin.size() > 1){
                pqMin.push(pqMax.top());
                pqMax.pop();
            }
            if(pqMax.size() > pqMin.size()){
                cout<<pqMax.top()<<" ";
            }else
            	cout<<(pqMax.top()+pqMin.top())/2<<" ";
        }else{
            pqMin.push(arr[i]);
            if(pqMin.size()-pqMax.size() > 1){
            	pqMax.push(pqMin.top());
                pqMin.pop();
            }
            if(pqMin.size() > pqMax.size()){
                cout<<pqMin.top()<<" ";
            }else
                cout<<(pqMax.top()+pqMin.top())/2<<" ";
        }
    }
}
int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    findMedian(arr,n);

    delete[] arr;
}
