#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int a[205], d, n;

ll dp[201][12][22];

ll foo(int idx, int k, ll sum)
{
    if(k==0)
    {
        return (sum%d==0);
    }

    if(idx>=n)  return 0;

    if(dp[idx][k][sum]!=-1) return dp[idx][k][sum];

    ll ret = 0, x = 0, y = 0;

    ll s = (sum%d + a[idx]%d)%d;

    if(s<0) s+=d;

    x = foo(idx+1, k-1, s);
    y = foo(idx+1, k, sum);

    ret = x+y;

    return dp[idx][k][sum] = ret;

}

int main()
{

    int test, cs = 0;

    scanf("%d", &test);

    while(test--)
    {

        int k, q, x, i;

        scanf("%d %d", &n, &q);

        for(i=0; i<n; i++)    scanf("%d", &a[i]);

        printf("Case %d:\n", ++cs);

        while(q--)
        {
            memset(dp, -1, sizeof dp);

            scanf("%d %d", &d, &k);

            printf("%lld\n", foo(0, k, 0LL));
        }

    }

    return 0;

}

