#include <bits/stdc++.h>
using namespace std;
 
typedef long long i64;
 
i64 dp[51][51][51];
 
int m, k;
 
i64 foo(int n, int k, int m)
{
    if(n<0)   return 0;
 
    if(n == 0)    return k<1;
 
    if(k<1)    return n==0;
 
    i64 &ret = dp[n][k][m];
 
    if(ret != -1)    return ret;
 
    ret = 0;
 
    for(int i = 1; i<=m; i++)
    {
        ret += foo(n-i, k-1, m);
    }
 
    return ret;
 
}
 
int main()
{
    int test, cs = 0;
 
    scanf("%d", &test);
 
    memset(dp, -1, sizeof(dp));
 
    while(test--)
    {
        int n, k, m;
 
        scanf("%d %d %d", &n, &k, &m);
 
        i64 res = foo(n, k, m);
 
        printf("Case %d: %lld\n", ++cs, res);
 
    }
    return 0;
}
