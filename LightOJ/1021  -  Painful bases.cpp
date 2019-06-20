#include<bits/stdc++.h>
using namespace std;
 
typedef long long i64;
 
char s[25];
int k, b, n;
i64 dp[1<<16][21];
 
int getDigit(int i)
{
    int p = s[i];
    if(s[i]<'A')   return p-'0';
    return (p - 'A' + 10);
}
 
i64 f(int mask, int mod)
{
    //if(mask + 1 == (1 << n)) return (mod == 0);
    if(__builtin_popcount(mask)>=n) return mod==0;
 
    i64 &ret = dp[mask][mod];
 
    if(ret != -1)   return ret;
 
    ret = 0;
 
    for(int i = 0; i<n; i++)
    {
        if((mask&(1<<i))==0)
        {
            int d = getDigit(i);
            int p = (mod*b + d)%k;
            ret += f(mask|(1<<i), p);
        }
    }
 
    return ret;
 
}
 
int main()
{
 
    int test, cs = 1;
 
    scanf("%d", &test);
 
    while(test--)
    {
 
        scanf("%d %d %s", &b, &k, &s);
 
        n = strlen(s);
 
        memset(dp, -1, sizeof(dp));
 
        long long res = f(0, 0);
 
        printf("Case %d: %lld\n", cs++, res);
 
    }
 
    return 0;
}
