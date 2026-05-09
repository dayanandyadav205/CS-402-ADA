// Exp No 03 Quick Sort Algorithm (Divide & Conquer Method)
#include<stdio.h>

int Partition(int arr[], int low, int high) {
	int pivot = arr[low];
	int i = low;
	int j = high;
	while(i < j) {
		do {
			i++;
		} while(arr[i]<= pivot);

		do {
			j--;
		} while(arr[j] > pivot);

		if(i < j) {
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
}
	
		int temp = arr[low];
		arr[low] = arr[j];
		arr[j] = temp;
	
	return j;
}

// Function definition
void Quick_Sort(int arr[], int low, int high)
 {
	if(low < high) {
		int j = Partition(arr, low, high);

		Quick_Sort(arr, low, j);
		Quick_Sort(arr, j + 1, high);
	}
}

int main() {
	printf("Exp No 03 Quick Sort Algorithm (Divide & Conquer Method) \n");
	
	int size;
	printf("Enter the size of array: ");
	scanf("%d", &size);

	int arr[size];
	printf("Enter %d elements in array:", size);
	for(int i=0; i<size; i++) {
		scanf("%d", &arr[i]);
	}

	Quick_Sort(arr, 0, size); // Merge sort Function call

	printf("The sorted array is: ");
	for(int i=0; i<size; i++) {
		printf("%d ", arr[i]);
	}
	return 0;

}