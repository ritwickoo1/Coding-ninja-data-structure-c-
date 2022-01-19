#include <iostream>
#include <algorithm>
using namespace std;

#include<algorithm>
int pairSum(int *arr, int n, int num)
{
    sort(arr,arr+n);
	int i = 0, k = n-1;
    int pair = 0;
	while(i < k){
        if((arr[i]+arr[k]) > num){
            k--;
        }else if((arr[i]+arr[k])<num){
            i++;
        }else{
            if(arr[i]==arr[k]){
                pair += ((k-i)*(k-i+1))/2;
                return pair;
            }else{ //if both are not same
                int a = 1, b = 1;
                while(arr[i]==arr[i+1]){
                    i++;a++;
                }
                while(arr[k]==arr[k-1]){
                    k--;b++;
                }
                pair+=a*b;
                i++;
                k--;
            }
        }
    }
    return pair;
}
int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int size;
		int x;

		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cin >> x;

		cout << pairSum(input, size, x) << endl;

		delete[] input;
	}
	
	return 0;
}