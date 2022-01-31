#include <iostream>
#include <vector>
using namespace std;

#include<vector>
#include<unordered_map>
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    // Your Code goes here
    vector<int> ans;
    unordered_map<int,bool> map;
    for(int i = 0; i < n; i++){
        map[arr[i]] = true;
    }
    int maxLength = 0;
    int start = 0;
    for(int i = 0; i < n; i++){
        int x = arr[i];
        int j = 0;
		if(map.count(x-1)>0){
			continue;
		}
		while(map.count(x)>0){
			x++;
			j++;
		}
		if(j > maxLength){
			maxLength = j;
			start = arr[i];
		}
    }
    ans.push_back(start);
	ans.push_back(start+maxLength-1);
	return ans;    
}
int main() {
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    vector<int> ans = longestConsecutiveIncreasingSequence(arr, size);

    for (auto i = ans.begin(); i != ans.end(); ++i)
        cout << *i << " ";

    delete[] arr;
}
