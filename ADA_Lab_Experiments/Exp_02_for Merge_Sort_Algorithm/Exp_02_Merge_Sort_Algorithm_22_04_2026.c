// Experiment No. 02 - Merge Sort algorithm using divide & conquer method
#include<stdio.h>

void Merge(int arr[], int low, int mid, int high)
{
	// Creating Sub Arrays
	int n1 = mid - low + 1;
	int n2 = high - low;
	
	int Left[n1], Right[n2];
	
	for(int i=0; i<n1; i++)
	{
		Left[i] = arr[low + i];
	}
	
	for(int j=0; j<n2; j++)
	{
		Right[j] = arr[mid + 1 + j];
	}
	
	//Left[n1 + 1] = 9999;
	//Right[n2 + 1] = 9999;


int i = 0;
int j = 0;
int k = low;

while(i < n1 && j < n2)
{
	if(Left[i] <= Right[j])
	{
		arr[k] = Left[i];
		i++;
	}
	else
	{
		arr[k] = Right[j];
		j++;
	}
	k++;
}

while(i < n1)
{
	arr[k] = Left[i];
	i++;
	k++;
}

while(j < n2)
{
	arr[k] = Right[j];
	j++;
	k++;
}
}

// Merge_Sort Function Definition
void Merge_Sort(int arr[], int low, int high)
{
	if(low < high)
	{
		int mid = (low + high)/2;
		Merge_Sort(arr, low, mid);
		Merge_Sort(arr, mid + 1, high);
		
		// Merge Function calling
		Merge(arr, low, mid, high);
	}
}

// Main function or Driver function
int main()
{
	printf("Exp_02_Merge_Sort_Algorithm using divide and conquer \n\n");
	
	int size;
	printf("Enter the size of array: ");
	scanf("%d", &size);
	
	int arr[size];
	printf("Enter %d elements in the array (unsorted): ", size);
	for(int i=0; i<size; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	// Merge Sort Function calling
	Merge_Sort(arr, 0, size-1);
	
	printf("The sorted is: ");
	for(int i=0; i<size; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}