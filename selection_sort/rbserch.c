#include <stdio.h>
#include <stdlib.h>
int RBsearch(int A[], int l, int h, int data)
{
	 int mid = (l+(h-l))/2;
	if (l > h)
	return 0;
	else
	{
	if (A[mid] == data)
	{
		return mid;

	}
	else if (A[mid]<data)
	{
       return RBsearch( A,  l,  mid+1, data);
	}
	else
		{return RBsearch( A,  mid-1, h, data);}
	return 0;
	}
	
}
int main(void)
{ int A[] = {1,2,3,4,5,5,6,7,8,9};
	int  y = RBsearch(A, 0, 9, 6);
	printf("%d\n", y);

	return 0;
}
