#include<bits/stdc++.h>
using namespace std;
 
int a[1005][1005];
int dp[1005][1005];
 
int main()
{
 
        int T, caseno=1;
 
        scanf("%d", &T);
 
        for(caseno=1; caseno<=T; caseno++)
        {
                memset(a, 0, sizeof a);
                memset(dp, 0, sizeof dp);
 
                int n, i, j;
 
                scanf("%d", &n);
 
                for(i=1; i<=n; i++)
                    for(j=1; j<=i; j++) scanf("%d", &a[i][j]);
 
                for(i=n+1; i<=2*n-1; i++)
                    for(j=1; j<=2*n-i; j++)  scanf("%d", &a[i][j]);
 
                for(i=1; i<=n; i++)
                    for(j=1; j<=i; j++)
                        dp[i][j]=max(dp[i-1][j], dp[i-1][j-1])+a[i][j];
 
                for(i=n+1; i<=2*n-1; i++)
                    for(j=1; j<=2*n-i; j++)
                        dp[i][j]=max(dp[i-1][j], dp[i-1][j+1])+a[i][j];
 
                printf("Case %d: %d\n", caseno, dp[2*n-1][1]);
 
 
        }
 
        return 0;
}
 