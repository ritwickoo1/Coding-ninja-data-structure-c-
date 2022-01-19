#include <iostream>
using namespace std;
//2
//5
//3 6 8 9 10
//4
//10 20 30 1
//Output
//0
//3
/*
Approach 1
int arrayRotateCheck(int *input, int size)
{
    //Write your code here
    int r = 0;
    for(int i = 0,j=size-1; i < j; i++,j--){
        int temp = input[i];
        input[i] = input[j];
        input[j] = temp;
    }
    for(int i = 0; i < size-1; i++){
        if(input[i] < input[i+1]){
            r = i+1;
            break;
        }
    }
    if(r==0){
        return 0;
    }
    return size-r;
}
*/
int arrayRotateCheck(int *input, int size){
    int left = 0;
    int right = size - 1;
    while (left < right) { 
        int mid = left + (right - left) / 2;
        if (input[mid] > input[right]) {
            left = mid + 1; 
        }
        else {
            right = mid;
        }
    }
    return left;
}
int main()
{

	int t;
	cin >> t;
	while (t--)
	{

		int size;
		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cout << arrayRotateCheck(input, size) << endl;
		delete[] input;
	}
	
	return 0;
}
