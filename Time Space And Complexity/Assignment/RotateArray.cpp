#include <iostream>
using namespace std;

/*
//Approach 1
void rotate(int *input, int d, int n)
{
    //Write your code here
    for(int i = 0; i < d; i++){
        int temp = input[0];
        for(int j = 0; j < n-1; j++){
            input[j] = input[j+1];
        }
        input[n-1] = temp;
    }
}
*/
//Approach 2
/*
void rotate(int *input, int d, int n){
    int *arr = new int[d];
    for(int i = 0; i < d; i++){
        arr[i] = input[i];
    }
    for(int i = 0; i < n-d;i++){
        input[i] = input[i+d];
    }
    int k =0;
    for(int i = n-d; i < n; i++){
        input[i] = arr[k++];
    }
}
*/
//Approach 3
void rotate(int *input, int d, int n){
	for(int i = 0, j = n-1; i < j; i++,j--){
        int temp = input[i];
        input[i] = input[j];
        input[j] = temp;
    }
    for(int i = 0, j = n-d-1; i < j; i++, j--){
        int temp = input[i];
        input[i] = input[j];
        input[j] = temp;
    }
    for(int i = n-d, j = n-1; i < j; i++, j-- ){
        int temp = input[i];
        input[i] = input[j];
        input[j] = temp;
    }
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

		for (int i = 0; i < size; ++i)
		{
			cin >> input[i];
		}

		int d;
		cin >> d;

		rotate(input, d, size);

		for (int i = 0; i < size; ++i)
		{
			cout << input[i] << " ";
		}
		
		delete[] input;
		cout << endl;
	}

	return 0;
}