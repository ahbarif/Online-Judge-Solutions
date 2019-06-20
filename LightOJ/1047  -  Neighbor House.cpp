#include<bits/stdc++.h>
using namespace std;

int main()
{

    int T, C;

    scanf("%d", &T);

    for(C=1; C<=T; C++)
    {

        int a[50][50], dp[100][100], n;

        memset(a, 0, sizeof(a));
        memset(dp, 0, sizeof(dp));

        cin>>n;

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=3; j++)
            {
                scanf("%d", &a[i][j]);
                if(i==1)    dp[i][j] = a[i][j];
            }

        }

        for(int i=2; i<=n; i++)
        {
            dp[i][1] = min(dp[i-1][2], dp[i-1][3]) + a[i][1];
            dp[i][2] = min(dp[i-1][1], dp[i-1][3]) + a[i][2];
            dp[i][3] = min(dp[i-1][1], dp[i-1][2]) + a[i][3];
        }

        int ans = INT_MAX;

        for(int i=1; i<=3; i++) ans = min(ans, dp[n][i]);

        printf("Case %d: %d\n", C, ans);

    }


    return 0;
}
