#include <stdio.h>
#include <stdlib.h>
int main() 
{
    int n, total_cost = 0;

    printf("Enter number of files: ");
    scanf("%d", &n);

    int files[n];
    printf("Enter sizes of %d files: ", n);
    for (int i = 0; i < n; i++) 
	{
        scanf("%d", &files[i]);
    }

    // Process until only one file is left
    while (n > 1) 
	{
        // Keep smallest elements at the beginning
        for (int i = 0; i < n - 1; i++) 
		{
        for (int j = 0; j < n - 1; j++) 
		{
            if (files[j] > files[j + 1]) 
			{
                int temp = files[j];
                files[j] = files[j + 1];
                files[j + 1] = temp;
            }
        }
    }
    
        // Merge the two smallest files
        int merged_size = files[0] + files[1];
        total_cost += merged_size;

        // Replace files[0] with the merged size and shift the rest
        files[0] = merged_size;
        
        for (int i = 1; i < n - 1; i++) 
		{
            files[i] = files[i + 1];
        }
        n--; // Reduce the count of available files
    }

    printf("Optimal Merge Cost: %d\n", total_cost);
    return 0;
}
