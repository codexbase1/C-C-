#include <stdio.h>
int fac(int n);
int comb(int x, int y);
int main(void)
{
	int z,k=0,n=0;

   z = comb(n,k);
        printf("%d", z);

    return 0;
}
int fac(int n)
{
    int i, f;
    if(n==0||n==1)
    {
		f=1;
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

int comb(int x, int y)
{
    int z;
    if(x>=y)
    {
      z = fac(x)/(fac(x-y)*fac(y));
      return z;
    }
    else
    {
        return 0;
    }
}
