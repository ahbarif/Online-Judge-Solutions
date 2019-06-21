#include<stdio.h>

int main()
{

        int test, i, a[3660], c=0, h, x, k;

        scanf("%d", &test);

        while(test--)
        {
                c=0;
                for(i=0; i<3660; i++)   a[i]=0;
                scanf("%d", &x);

                scanf("%d", &h);

                while(h--)
                {
                    scanf("%d", &k);

                    for(i=k; i<=x; i+=k)    a[i]=1;
                }

                for(i=0; i<3660; i++)
                {
                    if(a[i])
                    {
                        if(i%7==6 || i%7==0)    a[i]=0;
                    }
                }

                for(i=0; i<3660; i++)   if(a[i])    c++;

                printf("%d\n", c);


        }

    return 0;

}
