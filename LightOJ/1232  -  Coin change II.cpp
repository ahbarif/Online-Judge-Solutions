#include <iostream>
#include <cstdio>
#include <cstring>
 
using namespace std;
 
const int M = 100000007;
 
int dp[10005], a[102], n, k;
 
int main()
{
 
        int test, cs=1;
 
        scanf("%d", &test);
 
        while(test--)
        {
            memset(dp, 0, sizeof dp);
 
            scanf("%d %d", &n, &k);
 
            for(int i=1; i<=n; i++) scanf("%d", &a[i]);
 
            dp[0] = 1;
 
            for(int i=1; i<=n; i++)
            {
                for(int j=1; j<=k; j++)
                {
                    if(j-a[i]>=0)
                    {
                        dp[j] = (dp[j] + dp[j-a[i]])%M;
                    }
                }
            }
 
            printf("Case %d: %d\n", cs++, dp[k]);
 
        }
 
    return 0;
}
 