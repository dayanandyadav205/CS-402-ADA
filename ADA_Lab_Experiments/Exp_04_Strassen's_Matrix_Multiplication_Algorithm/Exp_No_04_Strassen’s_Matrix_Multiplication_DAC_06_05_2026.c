//EXPT. No. – 4 Write a program to implement Strassen’s matrix multiplication. 
#include <stdio.h>

void strassen(int n, int A[n][n], int B[n][n], int C[n][n]) 
{
    if (n == 2) 
    {   // Base case: 2x2 multiplication using Strassen’s formulas
        int p1 = (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]);
        int p2 = (A[1][0] + A[1][1]) * B[0][0];
        int p3 = A[0][0] * (B[0][1] - B[1][1]);
        int p4 = A[1][1] * (B[1][0] - B[0][0]);
        int p5 = (A[0][0] + A[0][1]) * B[1][1];
        int p6 = (A[1][0] - A[0][0]) * (B[0][0] + B[0][1]);
        int p7 = (A[0][1] - A[1][1]) * (B[1][0] + B[1][1]);

        C[0][0] = p1 + p4 - p5 + p7;
        C[0][1] = p3 + p5;
        C[1][0] = p2 + p4;
        C[1][1] = p1 + p3 - p2 + p6;
    }
    else
    {
        int k = n/2;
        int A11[k][k], A12[k][k], A21[k][k], A22[k][k];
        int B11[k][k], B12[k][k], B21[k][k], B22[k][k];
        int P[k][k], Q[k][k], R[k][k], S[k][k], T[k][k], U[k][k], V[k][k];
        int Temp1[k][k], Temp2[k][k];

        // Split matrices
        for (int i=0; i<k; i++) 
        {
            for (int j=0; j<k; j++) 
            {
                A11[i][j] = A[i][j];
                A12[i][j] = A[i][j+k];
                A21[i][j] = A[i+k][j];
                A22[i][j] = A[i+k][j+k];

                B11[i][j] = B[i][j];
                B12[i][j] = B[i][j+k];
                B21[i][j] = B[i+k][j];
                B22[i][j] = B[i+k][j+k];
            }
        }

        // P = (A11 + A22) * (B11 + B22)
        for(int i=0; i<k; i++)
            for(int j=0; j<k; j++)
                Temp1[i][j]=A11[i][j]+A22[i][j];

        for(int i=0; i<k; i++)
            for(int j=0; j<k; j++)
                Temp2[i][j]=B11[i][j]+B22[i][j];
                
        strassen(k, Temp1, Temp2, P);

        // Q = (A21 + A22) * B11
        for(int i=0; i<k; i++)
            for(int j=0; j<k; j++)
                Temp1[i][j]=A21[i][j]+A22[i][j];
                
        strassen(k, Temp1, B11, Q);

        // R = A11 * (B12 - B22)
        for(int i=0; i<k; i++)
            for(int j=0; j<k; j++)
                Temp2[i][j]=B12[i][j]-B22[i][j];
                
        strassen(k, A11, Temp2, R);

        // S = A22 * (B21 - B11)
        for(int i=0; i<k; i++)
            for(int j=0; j<k; j++)
                Temp2[i][j]=B21[i][j] - B11[i][j];
                
        strassen(k, A22, Temp2, S);

        // T = (A11 + A12) * B22
        for(int i=0; i<k; i++)
            for(int j=0; j<k; j++)
                Temp1[i][j]=A11[i][j] + A12[i][j];
                
        strassen(k, Temp1, B22, T);

        // U = (A21 - A11) * (B11 + B12)
        for(int i=0; i<k; i++)
            for(int j=0; j<k; j++)
                Temp1[i][j]=A21[i][j] - A11[i][j];

        for(int i=0; i<k; i++)
            for(int j=0; j<k; j++)
                Temp2[i][j]=B11[i][j] + B12[i][j];
                
        strassen(k,Temp1,Temp2,U);

        // V = (A12 - A22) * (B21 + B22)
        for(int i=0; i<k; i++)
            for(int j=0; j<k; j++)
                Temp1[i][j]=A12[i][j] - A22[i][j];

        for(int i=0; i<k; i++)
            for(int j=0; j<k; j++)
                Temp2[i][j]=B21[i][j] + B22[i][j];
                
        strassen(k,Temp1,Temp2,V);

        // Combine results
        for (int i=0; i<k; i++) 
        {
            for (int j=0; j<k; j++) 
            {
                C[i][j]       = P[i][j] + S[i][j] - T[i][j] + V[i][j];
                C[i][j+k]     = R[i][j] + T[i][j];
                C[i+k][j]     = Q[i][j] + S[i][j];
                C[i+k][j+k]   = P[i][j] + R[i][j] - Q[i][j] + U[i][j];
            }
        }
    }
}

int main() {
	printf("EXPT. No. 4 Write a program to implement Strassen’s matrix multiplication \n\n");
    int n;
    printf("Enter matrix size (must be power of 2): \n");
    scanf("%d", &n);

    int A[n][n], B[n][n], C[n][n];

    printf("Enter %dx%d Matrix A:\n", n, n);
    for(int i=0; i<n; i++) 
        for(int j=0; j<n; j++)
            scanf("%d", &A[i][j]);

    printf("Enter %dx%d Matrix B:\n", n, n);
    for(int i=0; i<n; i++) 
        for(int j=0; j<n; j++)
            scanf("%d", &B[i][j]);

    strassen(n, A, B, C);

    printf("\nResultant Matrix C:\n");
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++)
            printf("%d\t", C[i][j]);
        printf("\n");
    }
    return 0;
}
