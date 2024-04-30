// Find largest and smallest number simultaneously in an array using Divide & Conquer Principle


#include<stdio.h>

int max,min;
int a[100];

void maxmin(int i, int j)
{
	int max1,min1,mid;
	if(i==j)
	{
		max = min = a[i];
	}
	else
	{
		if(i==j-1)
		{
			if(a[i]<a[j])
			{
				max = a[j];
				min = a[i];
			}
			else
			{
				max = a[i];
				min = a[j];
			}
		}
		else
		{
			mid = (i+j)/2;
			maxmin(i,mid);
			max1 = max;
			min1 = min;
			maxmin(mid+1, j);
			if(max<max1)
			{
				max = max1;
			}
			if(min>min1)
			{
				min=min1;
			}
		}
	}
}

int main()
{
	int i, num;
	printf("\nEnter the total number of elements: ");
	scanf("%d", &num);
	printf("Enter the numbers:\n");
	for(i =1; i<=num; i++)
	{
		scanf("%d", &a[i]);
	}
	max = a[0];
	min = a[0];
	maxmin(1,num);
	printf("Minimum element in array: %d\n", min);
	printf("Maximum element in array: %d\n", max);
	return 0;
}

/*
#include <stdio.h>

// Function to find the maximum and minimum in an array using divide and conquer
void findMaxMin(int arr[], int low, int high, int *max, int *min) {
    if (low == high) {
        *max = *min = arr[low]; // Base case: Single element in array
    } else if (high - low == 1) {
        *max = (arr[low] > arr[high]) ? arr[low] : arr[high]; // Compare two elements
        *min = (arr[low] < arr[high]) ? arr[low] : arr[high];
    } else {
        int mid = (low + high) / 2;
        int leftMax, leftMin, rightMax, rightMin;

        // Divide the array into two halves and recursively find max and min
        findMaxMin(arr, low, mid, &leftMax, &leftMin);
        findMaxMin(arr, mid + 1, high, &rightMax, &rightMin);

        // Merge the results
        *max = (leftMax > rightMax) ? leftMax : rightMax;
        *min = (leftMin < rightMin) ? leftMin : rightMin;
    }
}

int main() {
    int arr[] = {12, 45, 67, 8, 90, 6, 23, 78};
    int size = sizeof(arr) / sizeof(arr[0]);
    int max, min;

    findMaxMin(arr, 0, size - 1, &max, &min);

    printf("Maximum element in the array: %d\n", max);
    printf("Minimum element in the array: %d\n", min);

    return 0;
}

*/




