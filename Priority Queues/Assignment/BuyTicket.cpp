#include <iostream>
#include <vector>
using namespace std;

#include<queue>
int buyTicket(int *arr, int n, int k) {
    // Write your code here
    queue<int> q;
    priority_queue<int> pq;
    for(int i = 0;i < n; i++){
        q.push(i);
        pq.push(arr[i]);
    }
    int timer = 0;
    while(true){
        if(q.front()==k && arr[q.front()] == pq.top()){
        	//cout<<q.front()<<" "<<k<<endl;
            timer++;
            break;
        }else if(pq.top() == arr[q.front()]){
        	//cout<<pq.top()<<" "<<q.front()<<endl;
            pq.pop();
            q.pop();
            timer++;
        }else{
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
    }
    return timer;
}
int main() {
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    cout << buyTicket(arr, n, k);

    delete[] arr;
}