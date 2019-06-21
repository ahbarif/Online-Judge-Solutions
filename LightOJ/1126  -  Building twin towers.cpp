#include<bits/stdc++.h>
using namespace std;

int dp[2][500005];
int a[105];

int main()
{

  //  freopen("in.txt", "r", stdin);

    int test, cs = 0;

    scanf("%d", &test);

    while(test--){


        int n;

        scanf("%d", &n);

        for(int i = 1; i<=n; i++) scanf("%d", &a[i]);

        int sum = accumulate(a+1, a+n+1, 0)/2;

        sort(a+1, a+n+1);

        memset(dp, -1, sizeof(dp));

        dp[0][0] = 0;

        for(int i = 1; i<=n; i++){

            int cur = i&1, prev = cur^1;

            for(int j = 0; j<=sum; j++){
                dp[cur][j] = max(dp[cur][j], dp[prev][j]);

                if(dp[prev][j] == -1) continue;

                if(abs(j-a[i])<=sum){
                    dp[cur][abs(j-a[i])] = max(dp[cur][abs(j-a[i])], dp[prev][j] + a[i]);
                }

                 if(abs(j+a[i])<=sum){
                    dp[cur][abs(j+a[i])] = max(dp[cur][abs(j+a[i])], dp[prev][j] + a[i]);
                }


            }
        }

        printf("Case %d: ", ++cs);

        if(dp[n&1][0] == 0) puts("impossible");

        else printf("%d\n", dp[n&1][0]/2);

    }

    return 0;
}

