#include <stdio.h>
int main(void)
{
	int num1, num2, hcf=1, i;
	int min=0;
	printf("enter any two numbers\n");
	scanf("%d%d", &num1, &num2);
	if(num1<num2)
	{
		min = num2-num1;
	}
	else
	{
       min = num1-num2;
	}
	for(i=1; i<=min; i++)
	{
		if((num1%i==0) && (num2%i==0))
		{
			hcf = i;
		}
		else 
		{}
	}
    printf("the hcf of %d and  %d is %d\n", num1, num2, hcf);
		return 0;
}
