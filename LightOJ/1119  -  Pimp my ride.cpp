#include<bits/stdc++.h>
using namespace std;
 
template < class T > inline T SET(T n, T pos)
{
    return n|(1<<pos);
}
template < class T > inline T RESET(T n,T pos)
{
    return n & ~((T)1<<pos);
}
template < class T > inline bool isOn(T n,T pos)
{
    return (bool)(n & ((T)1<<pos));
}
 
int dp[16][1<<16];
 
int n, adj[15][15];
 
int func(int idx, int mask)
{
 
    int done = 1;
 
    if(dp[idx][mask]!=-1)   return dp[idx][mask];
 
    int ret = INT_MAX, prev = 0;
 
    for(int i=0; i<n; i++)
    {
        if(isOn(mask, i))   prev += adj[idx][i];
 
        else done = 0;
    }
 
    if(done) return dp[idx][mask] = prev;
 
 
    for(int i=0; i<n; i++)
    {
        if(!isOn(mask, i))
        {
            int p = SET(mask, i);
 
            ret = min(ret, func(i, p));
        }
    }
 
    return dp[idx][mask] = ret + prev;
 
 
}
 
 
int main()
{
 
    int test, cs = 0;
 
    scanf("%d", &test);
 
    while(test--)
    {
 
        memset(dp, -1, sizeof(dp));
 
        int i, j;
 
        scanf("%d", &n);
 
        for(i = 0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                scanf("%d", &adj[i][j]);
            }
        }
 
        int res = func(0, 0);
 
        printf("Case %d: %d\n", ++cs, res);
 
    }
 
    return 0;
 
}
 