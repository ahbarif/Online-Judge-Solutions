#include <bits/stdc++.h>
using namespace std;
 
int a[10005], n;
int dp[1005][3];
 
int f(int i, bool one)
{
    if(i>n)    return 0;
 
    if(dp[i][one]!=-1)  return dp[i][one];
 
    int x = 0, y = 0;
 
    if(i==1)    x = a[i] + f(i+2, 1);
 
    else if(i==n)
    {
        if(one==0)  x = a[i] + f(i+2, one);
        else x = f(i+2, one);
    }
 
    else x = a[i] + f(i+2, one);
 
    y = f(i+1, one);
 
 
    return dp[i][one] = max(x, y);
 
 
}
 
int main()
{
 
        int T, C;
 
        scanf("%d", &T);
 
        for(C=1; C<=T; C++)
        {
            memset(dp, -1, sizeof(dp));
 
            scanf("%d", &n);
 
            for(int i=1; i<=n; i++)  scanf("%d", &a[i]);
 
            printf("Case %d: %d\n", C, f(1, 0));
        }
 
        return 0;
 
 
}
 