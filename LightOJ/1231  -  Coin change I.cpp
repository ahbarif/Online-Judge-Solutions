#include <bits/stdc++.h>
using namespace std;
 
long long dp[55][25][1005];
bool vis[55][25][1005];
 
int n, a[55], c[55], k;
const long long M = 100000007;
 
long long f(int i, int taken_i, int amount)
{
 
        if(i>=n )       return amount==0;
        if(amount==0)   return 1;
        if(amount<0)    return 0;
 
        if(vis[i][taken_i][amount])   return dp[i][taken_i][amount];
 
        long long x = 0, y = 0;
 
        if(amount-a[i]>=0 && taken_i<=c[i])  x = f(i, taken_i+1, amount-a[i])%M;
 
        y = f(i+1, 1, amount)%M;
 
        vis[i][taken_i][amount] = 1;
        return dp[i][taken_i][amount] = ((x%M)+(y%M))%M;
 
}
 
 
int main()
{
 
        int test, cs=0;
 
        scanf("%d", &test);
 
        while(test--)
        {
 
            memset(vis, 0, sizeof vis);
 
            scanf("%d %d", &n, &k);
 
            for(int i=0; i<n; i++)  scanf("%d", &a[i]);
            for(int i=0; i<n; i++)  scanf("%d", &c[i]);
 
            printf("Case %d: %lld\n", ++cs, f(0, 1, k)%M);
 
        }
 
 
    return 0;
 
}