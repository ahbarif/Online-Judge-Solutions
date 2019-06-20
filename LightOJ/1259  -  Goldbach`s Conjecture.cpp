#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
bool primes[10000002];
const int N = 10000000;
int a[700000];
 
void sieve()
{
        int i, j;
        primes[1]=1;
        a[0]=2;
 
        for(i=3; i*i<=N; i+=2)
        {
            if(primes[i]==0)
            {
                for(j=i*i; j<=N; j+=(2*i))
                {
                    primes[j]=1;
                }
            }
        }
 
        for(i=2; i<=N/2; i++)   primes[2*i]=1;
 
}
 
int main()
{
 
        sieve();
 
        int index=1, i, test, ans=0, n, tc=0;
 
        a[0]=2;
 
        for(i=3; i<=N; i++)
        {
            if(primes[i]==0)
            {
                a[index++]=i;
            }
        }
 
        scanf("%d", &test);
 
        while(test--)
        {
            scanf("%d", &n);
            ans=0;
            for(i=0; i<index; i++)
            {
                int k=a[i];
                int f=n-k;
                if(k>f) break;
                if(primes[k]==0 && primes[f]==0)
                {
 
                    ans++;
                }
            }
            printf("Case %d: %d\n", ++tc, ans);
        }
    return 0;
}