#include <stdio.h>
int main(void)
{
	int num, la, sum;
	int sto = 0;
	printf("enter a number\n");
	scanf("%d", &num);
	la = num%10;
	while(num>10)
	{
			num = num/10;
	}
	sum = la+num;
		printf("%d\n", sum);
		return 0;
}
