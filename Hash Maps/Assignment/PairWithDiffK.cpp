#include <iostream>
using namespace std;
#include<unordered_map>
int getPairsWithDifferenceK(int *arr, int n, int k) {
	// Write your code here
	unordered_map<int,int>map;
	for(int i = 0; i < n; i++){
		map[arr[i]]++;
	}
	int count=0;
	if(k!=0){
	
		for(int i = 0; i < n; i++){
			if(map[arr[i]-k]>0){
				count += map[arr[i]]*map[arr[i]-k];
			}
			if(map[arr[i]+k]>0){
				count += map[arr[i]]*map[arr[i]+k];
			}
			map[arr[i]] = 0;
		}
	}else{
		for(int i =0; i < n; i++){
			if(map[arr[i]]>0){
				count+=(map[arr[i]]-1);
				map[arr[i]]--;
			}
			
		}
	}
	return count;
}
int main() {
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    int k;
    cin >> k;

    cout << getPairsWithDifferenceK(input, n, k);

    delete[] input;
}