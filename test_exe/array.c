#include <stdio.h>
int main(void)
{
	int arr[10][10], arrb[10][10], arra[10][10], i, j, k=0,n, p=0, l, l2;
	printf("enter the size of your n by n matrix\n");
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			arr[i][j]= 0;
		}
	}
printf("enter the  your matrix element for matrix 1\n");
	for(i=0; i<n; i++)
{
		for(j=0; j<n; j++)
		{
			scanf("%d", &arrb[i][j]);
		}
		printf("\n");
	}

printf("enter the  your matrix element for matrix 2\n");
	for(i=0; i<n; i++)
{
		for(j=0; j<n; j++)
		{
			scanf("%d", &arr[i][j]);
		}
		printf("\n");
	}

for(i=0; i<n; i++)
{
		for(j=0; j<n; j++)
		{
			if(i==j)
			{
				k = k+arr[i][i];

			}
			else
			{}

		}
	}
	printf("the trace is : %d\n", k);
for(i=0; i<n; i++)
{
		for(j=0; j<=n-1; j++)
		{
			p = p + arr[i][j];
		}
	}
printf("the sume of elements in the matrix is : %d\n", p);
l = arr[0][0];

	for(i=0; i<=n-1; i++)
{
		for(j=0; j<=n-1; j++)
		{

			if(l<arr[i][j])
				{
					l  = arr[i][j];
			    }       
		}
	}//**********************************************************************************
for(i=0; i<n; i++)
{
		for(j=0; j<=n-1; j++)
		{
			arra[i][j] = arr[i][j]+ arrb[i][j];
		}
	}



printf("the max elements in the matrix is : %d\n", l);

for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			printf("%4d",arra[i][j]);
		}
		printf("\n");
	}
	return 0;
}
