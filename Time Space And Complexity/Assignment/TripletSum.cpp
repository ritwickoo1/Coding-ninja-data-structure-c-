#include <iostream>
#include <algorithm>
using namespace std;

#include<algorithm>
int pairsum(int *arr,int i,int j,int num)
{
    int k=0;
    while(i<j)
    {
        if(arr[i]+arr[j]>num) // if sum of first and last turns out to be greater than num
        {
            j--;//then move j one step back
        }
        else if(arr[i]+arr[j]<num)//if sum of first and last turns out to be less than num
        {
            i++;//then move i one step forward
        }
        else//now the sum turns out to be =
        {
            if(arr[i]==arr[j])//if both the elements are same 
            {
               k += ((j-i+1)*((j-i)))/2;//no of pairs that are possible
                return k;
            }
            else//if both are not same 
            {
                int a=1,b=1;
                while(arr[i]==arr[i+1])//to chk for duplicacy
                {
                    i++;a++;
                }
                while(arr[j]==arr[j-1])//to chk for duplicacy
                {
                    j--;b++;
                }
                k += a*b;//no of possible pairs
                i++;
                j--;
            }
        }
       
    }
     return k;
}
int tripletSum(int *arr, int n, int num)
{
	sort(arr,arr+n);
    int pairs=0;
    for(int i=0;i<n;i++)
    {
        pairs += pairsum(arr,i+1,n-1,num-arr[i]);//in every iteration we are taking 2 elements at a time and then computing for every possibility
    }
    return pairs;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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

		cout << tripletSum(input, size, x) << endl;

		delete[] input;
	}

	return 0;
}