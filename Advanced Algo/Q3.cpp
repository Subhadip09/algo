// Given a sorted array and a number x, search two elements of the 
// array such their sum is x. Expected time complexity is O(n^2) and O(n)

#include<stdio.h>

void findPair(int arr[], int n, int target)
{
	int left = 0, right = n-1;
	while(left < right)
	{
		int sum = arr[left] + arr[right];
		if(sum == target)
		{
			printf("Pair formed: %d, %d\n", arr[left], arr[right]);
			return ;
		}
		else if(sum< target)
		{
			left++;
		}
		else
		{
			right--;
		}
	}
	printf("Pair not formed\n");
}

int main()
{
	int arr[] = {1,3,5,7,9,11,13};
	int n = sizeof(arr)/sizeof(arr[0]);
	int target = 16;
	findPair(arr,n,target);
	return 0;
}

