// Apply strassen's matrix multiplication strategy for odd dimensional square matrices

#include<stdio.h>
#define Row_1 3
#define Col_1 3
#define Row_2 3
#define Col_2 3

void MatMultiplication(int Mat_A[][Col_1], int Mat_B[][Col_2])
{
	int result[Row_1][Col_2];
	
	for(int i=0; i<Row_1; i++)
	{
		for(int j=0; j<Col_2; j++)
		{
			result[i][j] = 0;
			for(int k=0; k<Row_2; k++)
			{
				result[i][j] += Mat_A[i][k] * Mat_B[k][j];
			}
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int Mat_A[Row_1][Col_1] = {{1,2,3},{4,5,6},{7,8,9}};
	int Mat_B[Row_2][Col_2] = {{6,1,1},{9,2,4},{10,3,6}};
	if(Col_1 != Row_2)
	{
		printf("Matrix Multiplication not possible\n");
	}
	MatMultiplication(Mat_A, Mat_B);
	return 0;
}
