#include <bits/stdc++.h>
using namespace std;
 
int dp[2][15002];
 
const int M = 100000007;
 
int main()
{
    int test, cs = 0;
 
    scanf("%d", &test);
 
    while(test--)
    {
        int n, k, sum;
 
        scanf("%d %d %d", &n, &k, &sum);
 
        memset(dp, 0, sizeof(dp));
 
        int prev = 0, now = 1, res = 0;
 
        dp[0][0] = 1;
 
        for(int i = 1; i<=n; i++)
        {
            dp[now][0] = 0;
 
            for(int j = 1; j<=sum; j++)
            {
                dp[now][j] = (dp[now][j-1] + dp[prev][j-1]);
 
                int lm = j-k-1;
 
                if((j-k-1)>=0)  dp[now][j] -= dp[prev][lm];
 
                dp[now][j] = (dp[now][j]+M)%M;
 
            }
 
            swap(now, prev);
 
        }
 
        printf("Case %d: %d\n", ++cs, (dp[prev][sum] + M )%M);
 
    }
    return 0;
}
 
