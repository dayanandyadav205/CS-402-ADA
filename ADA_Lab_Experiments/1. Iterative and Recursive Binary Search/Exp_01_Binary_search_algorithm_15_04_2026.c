// Exp_01_Binary_search_algorithm_15_04_2026
#include<stdio.h>
int main()
{
	int a[15], key, found = 0;
	int n = sizeof(a)/sizeof(a[0]);
	//printf("Size of double %d", sizeof(double));                                           
	      
	printf("Exp_01_Binary_search_algorithm \n\n");
	
	printf("Enter %d elements in array = ", n);
	for(int i=1; i<=n;i++)
	{
		scanf("%d", &a[i]);
	}
	
	printf("Enter the Element you want to search: ");
	scanf("%d", &key);
	
	int low = 1;
	int high = 15;
	
	while(low<=high)
	{
		int mid = (low+high)/2;
		if(key<a[mid])
		{
			high = mid - 1;
		}
		if(key>a[mid])
		{
			low = mid + 1;
		}
		if(key == a[mid])
		{
			printf("Element found @ location %d ", mid);
			found = 1;
			break;
		}
	}
	if(!found)
	{
		printf("Element not found");
	}
	return 0;
}