#include <stdio.h>
int comb(int, int);
int fac(int);
int n = 8;
int main(void)
{

    int i, j,k=0, p, u;
    for(i=0;i<=n;++i)
    {
        k=0;
        for(j=n-(i+1);j>=0;--j){
        }
       while(k<=i)
       {
           p = comb(i,k);

           printf("%2d", p);
           k++;
        }

        printf("\n");
}
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

int comb(int x, int y)
{
    int z;
    if(x>y)
    {
     z = fac(x)/(fac(x-y)*fac(y));
      return z;
    }
    else
    {
        return 1;
    }
}



