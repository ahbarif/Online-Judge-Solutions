#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long a[100010], test, j, i, p, query, querytype, x, v, n;

    long long sum=0, k;

    scanf("%lld", &test);

    for(j=1; j<=test; j++)
    {
        memset(a, 0, sizeof(a));

        sum=0;
        p=1;

        printf("Case %lld:\n", j);

        scanf("%lld %lld", &n, &query);

        for(i=0; i<n; i++)
        {
            scanf("%lld", &a[i]);
            k=(n-p)*(long long)a[i];
            sum+=k;
            p+=2;
        }

        while(query--)
        {
            scanf("%lld", &querytype);

            if(querytype==1)    printf("%lld\n", sum);

            else
            {
                scanf("%lld %lld", &x, &v);
                p=2*x+1;
                k=(n-p)*(v-a[x]);
                sum+=k;
                a[x]=v;
            }

        }

    }
    return 0;
}
