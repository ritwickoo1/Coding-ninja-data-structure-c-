#include <iostream>
using namespace std;

#include <stack>
#include <queue>
/* using stack
void reverseQueue(queue<int> &input) {
	// Write your code here
    stack<int> extra;
    while(!input.empty()){
        extra.push(input.front());
        input.pop();
    }
    while(!extra.empty()){
        input.push(extra.top());
        extra.pop();
    }
}
*/
// using queue
void reverseQueue(queue<int> &input) {
	// Write your code here
	if(input.empty()) return;
    int x = input.front();
    input.pop();
    reverseQueue(input);
    input.push(x);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        queue<int> q;
        int size;
        cin >> size;

        for (int i = 0, val; i < size; i++) {
            cin >> val;
            q.push(val);
        }

        reverseQueue(q);
        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }

        cout << "\n";
    }
}