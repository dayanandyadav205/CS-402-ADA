//Greedy_Knapsack_Problem_Fractional
#include <stdio.h>

int main() 
{
    int n = 7, capacity = 15;
    float profit[] = {10, 5, 15, 7, 6, 18, 3};
    float weight[] = {2, 3, 5, 7, 1, 4, 1};
    float ratio[7]; // Fixed size to match n
	float temp; 
    float totalProfit = 0;

    // 1. Calculate ratios (using 0-based indexing)
    for (int i = 0; i < n; i++) 
	{
        ratio[i] = profit[i] / weight[i];
    }


    // 2. Simple Bubble Sort 
	// To Sort Ratios, Weight & Profit in Descending order
    for (int i = 0; i < n; i++) 
	{
        for (int j = i + 1; j < n; j++) 
		{
            if (ratio[i] < ratio[j]) 
			{
                // Swap ratios
                temp = ratio[i]; 
                ratio[i] = ratio[j]; 
                ratio[j] = temp;
                
                // Swap weights
                temp = weight[i]; 
                weight[i] = weight[j]; 
                weight[j] = temp;
                
                // Swap profits
                temp = profit[i]; 
                profit[i] = profit[j]; 
                profit[j] = temp;
            }
        }
    }

    printf("Sorted Profit/Weight Ratio: \n");
     for (int i = 0; i < n; i++) 
	{
 		printf("%.1f\n", ratio[i]);
    }
     printf("\n");

    // 3. Fill the knapsack
    for (int i = 0; i < n; i++) 
    {
        if (weight[i] <= capacity) 
        {
            totalProfit += profit[i];
            capacity -= weight[i];
        } 
        else 
        {
            // Take fraction of the remaining item
            totalProfit += profit[i] * (capacity / weight[i]);
            break;
        }
    }

    printf("Maximum Profit: %f", totalProfit);
}
