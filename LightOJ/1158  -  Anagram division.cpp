#include <bits/stdc++.h>
using namespace std;
 
int dp[5 + (1<<10)][1003];
int len, a[15], c[15], fac[15], d;
 
int f(int mask, int mod)
{
    if(__builtin_popcount(mask) == len)
    {
        if(mod==0) return 1;
        else return 0;
 
    }
 
    if(dp[mask][mod] != -1) return dp[mask][mod];
 
    int res = 0;
 
    for(int i = 0; i<len; i++)
    {
        if((mask&(1<<i)) == false)
        {
            res = res + f(mask|(1<<i), (mod*10 + a[i])%d);
        }
    }
 
    return dp[mask][mod] = res;
 
}
 
void pre()
{
    fac[0] = 1;
    fac[1] = 1;
 
    for(int i = 2; i<=10; i++)  fac[i] = i*fac[i-1];
}
 
int main()
{
    int test, cs = 0;
 
    scanf("%d", &test);
 
    pre();
 
    while(test--)
    {
        memset(dp, -1, sizeof(dp));
        memset(c, 0, sizeof(c));
 
        char s[15];
 
        scanf("%s", s);
        scanf("%d", &d);
 
        len = strlen(s);
 
        for(int i = 0; i<len; i++)
        {
            int x = s[i] - '0';
            a[i] = x;
            c[x]++;
        }
 
        int res = f(0, 0);
 
        for(int i = 0; i<=10; i++)  res/= fac[c[i]];
 
        printf("Case %d: %d\n", ++cs, res);
 
    }
    return 0;
}
