// Write a code to perform quick sort

#include<stdio.h>

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low-1);
	for(int j = low; j<=high-1; j++)
	{
		if(arr[j] <= pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[high]);
	return (i+1);
}

void quickSort(int a[], int p, int r)
{
	if(p<r)
	{
		int q;
		q = partition(a,p,r);
		quickSort(a,p,q-1);
		quickSort(a,q+1,r);
	}
}

void printArray(int a[], int size)
{
	int i;
	for(i = 0; i<size; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main()
{
	int arr[50];
	int n;
	printf("Enter the number of elements you want to add in the array: ");
	scanf("%d", &n);
	printf("Enter the elements:\n");
	for(int i=0; i<n; i++)
	{
		scanf("%d", &arr[i]);
	}
	quickSort(arr, 0, n-1);
	printf("Sorted array:\n");
	printArray(arr,n);
	return 0;
}
/*
Enter the number of elements you want to add in the array: 10
Enter the elements:
12
53
25
60
39
87
9
78
95
36
Sorted array:
9 12 25 36 39 53 60 78 87 95
*/
