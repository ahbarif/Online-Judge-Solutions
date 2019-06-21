#include<stdio.h>

int main()
{

        int n, a[100], i, sum, avg, ans=0, x=0;

        while(1)
        {
            sum=0; ans=0;
            scanf("%d", &n);

            if(n==0)    break;

            for(i=0; i<n; i++)
            {
                scanf("%d", &a[i]);
                sum+=a[i];
            }

            avg=sum/n;

            for(i=0; i<n; i++)
            {
                if(a[i]>avg)
                {
                    ans=ans+(a[i]-avg);
                }
            }

            printf("Set #%d\n", ++x);

            printf("The minimum number of moves is %d.\n\n", ans);

        }

    return 0;

}
