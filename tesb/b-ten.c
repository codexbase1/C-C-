#include <stdio.h>
#include <math.h>
int main(void)
{
	long long num1, num2, place , i=0,p=0; 
		char coll[100];
	printf("enter a binary number\n");
	scanf("%s",coll);
	
		while(coll[i]<100)
		{
			if(coll[i]== '1')
				{
			p = pow(2,i)+p;
			
		}
		else
		{
			0*pow(2,i)+p;
		}
		i++;
		}
	
		printf("%lld\n",p);
	
	return 0;
}
