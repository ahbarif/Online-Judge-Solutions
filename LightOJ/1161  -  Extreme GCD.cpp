#include<bits/stdc++.h>
using namespace std;
 
typedef long long i64;
 
i64 nC4(i64 n)
{
    return ((n*(n-1)*(n-2)*(n-3))/24);
}
 
i64 dp[10005];
int a[10005];
 
int main()
{
 
    int test, cs = 0;
 
    scanf("%d", &test);
 
    while(test--)
    {
        int n, x, mx = -1;
 
        scanf("%d", &n);
 
        memset(dp, 0, sizeof(dp));
        memset(a, 0, sizeof(a));
 
        while(n--)
        {
            scanf("%d", &x);
            a[x]++;
 
            if(x>mx) mx = x;
        }
 
        for(int i = mx; i>=1; i--)
        {
            i64 sum = a[i];
 
            for(int j = i+i; j<=mx; j+=i)
            {
                sum += a[j];
 
                dp[i] -= dp[j];
 
            }
 
            dp[i] += nC4(sum);
 
        }
 
        printf("Case %d: %lld\n", ++cs, dp[1]);
 
    }
 
    return 0;
}
