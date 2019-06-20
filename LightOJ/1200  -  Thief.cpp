#include <bits/stdc++.h>
using namespace std;
 
int dp[102][10002], cost[102], w[102], n;
bool vis[102][10002];
 
int cap;
 
int knapsack(int i, int cur)
{
    if(i>=n) return 0;
 
    if(vis[i][cur])  return dp[i][cur];
 
    vis[i][cur] = 1;
 
    int x = 0, y = 0;
 
    if(cur + w[i]<=cap)   x = cost[i] + knapsack(i, cur+w[i]);
 
    y = knapsack(i+1, cur);
 
    return dp[i][cur] = max(x, y);
}
 
 
int main()
{
 
    int test, cs = 0, y;
 
    scanf("%d", &test);
 
    while(test--)
    {
        memset(vis, 0, sizeof(vis));
 
        scanf("%d %d", &n, &cap);
 
        for(int i = 0; i<n; i++)
        {
 
            scanf("%d %d %d", &cost[i], &y, &w[i]);
 
            cap -= (w[i]*y);
        }
 
        if(cap<0)  printf("Case %d: Impossible\n", ++cs);
 
        else
        {
 
            int res = knapsack(0, 0);
 
            printf("Case %d: %d\n", ++cs, res);
        }
 
    }
 
}
 
