#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
   int  a, i, n;
	
   printf("enter  an integer\n");
   scanf("%d", &n);
	i = 1;
   while(i<=n){
   a = rand() %100 +1;
	printf("%d\n", a);
       i++;
	}
   
    return 0;
}
