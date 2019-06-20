#include<bits/stdc++.h>
using namespace std;
 
int dp[1005][3];
int n, a[1001][3], t[1001][3];
 
int main()
{
 
    int test, cs = 0;
 
    scanf("%d", &test);
 
    while(test--)
    {
        scanf("%d", &n);
 
        memset(dp, 0, sizeof(dp));
 
        for(int i = 1; i<=n; i++) scanf("%d", &a[i][1]);
        for(int i = 1; i<=n; i++) scanf("%d", &a[i][2]);
 
        for(int i = 1; i<n; i++) scanf("%d", &t[i][1]);
        for(int i = 1; i<n; i++) scanf("%d", &t[i][2]);
 
        dp[1][1] = a[1][1];
        dp[1][2] = a[1][2];
 
        for(int i = 2; i<=n; i++)
        {
            dp[i][1] = a[i][1] + min(dp[i-1][1], dp[i-1][2] + t[i-1][2]);
            dp[i][2] = a[i][2] + min(dp[i-1][2], dp[i-1][1] + t[i-1][1]);
        }
 
        int res = min(dp[n][1], dp[n][2]);
 
        printf("Case %d: %d\n", ++cs, res);
 
    }
 
    return 0;
 
 
}
