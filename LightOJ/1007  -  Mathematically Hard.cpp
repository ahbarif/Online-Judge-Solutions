#include<bits/stdc++.h>
using namespace std;

const int N = 5000009;

bool prime[N+5];

unsigned long long sum[N+5];

void euler_phi()
{

    prime[1]=prime[0]=1;

    for(int i=4; i<=N; i+=2)    prime[i]=true;

    for(int i=3; i<=N; i++)     sum[i]=i;

    sum[1]=0;

    for(int i=2; i<=N; i++)
    {
        if(!prime[i])
        {
            sum[i]=i-1;

            for(int j=2*i; j<=N; j+=i)
            {
                prime[j]=1;
                sum[j]/=i;
                sum[j]*=(i-1);
            }
        }
    }
}


int main()
{

    euler_phi();

    int test, tc=0, i, x, y;

    for(i=1; i<=N; i++) sum[i]*=sum[i];

    for(i=1; i<=N; i++) sum[i]+=sum[i-1];

    scanf("%d", &test);

    while(test--)
    {
        scanf("%d %d", &x, &y);

        printf("Case %d: %llu\n", ++tc, sum[y]-sum[x-1]);

    }
       return 0;
}