#include <stdio.h>
int fac(int);
int main(void)
{
	int num, la, fs,sum=0, sto, i; 
	printf("enter a number\n");
	scanf("%d",&num);
while(num>0)
	{
        la = fac(num%10);
		printf("%d\n", la);
		sum = sum+la;
			num = num/10;
	
	}
	printf("%d\n", sum);
	return 0;
}
int fac(int n)
{
    int i, f=1;
    if(n==0||n==1)
    {
        return f;
    }
    else
    {
        for(i=n;i>=1;i--)
        {
            f = i*f;
        }
        return f;
    }
}
