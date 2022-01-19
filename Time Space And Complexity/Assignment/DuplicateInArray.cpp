#include <iostream>
using namespace std;
int findDuplicate(int *arr, int n)
{
    //Write your code here
    int sumn = 0;
    for(int i = 0; i < n; i++){
        sumn+=arr[i];
    }
    int sum2 = 0;
    for(int i = 0; i < n-1; i++){
        sum2 += i;
    }
    int ans = (sumn) - (sum2);
    return ans;
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

		cout << findDuplicate(input, size) << endl;
	}

	return 0;
}