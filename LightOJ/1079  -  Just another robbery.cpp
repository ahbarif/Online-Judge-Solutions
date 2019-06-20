#include<bits/stdc++.h>
using namespace std;

double dp[101][10001];

int a[105];
double p[105];

int cs = 0;

const double eps = 1e-9;

void solve(){

    memset(dp, 1, sizeof(dp));

    for(int i = 0; i<10001; i++) dp[0][i] = 2;
    dp[0][0] = 0;

    int n, sum = 0;

    double prop;

    scanf("%lf %d", &prop, &n);

    for(int i = 1; i<=n; i++){
        scanf("%d %lf", &a[i], &p[i]);
        sum += a[i];
    }

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=sum; j++){
            dp[i][j] = dp[i-1][j];
            if(j-a[i]>=0) dp[i][j] = min(dp[i][j], dp[i-1][j-a[i]] + (1.0 - dp[i-1][j-a[i]])*p[i]);
        }
    }

    int res = 0;
    for(int i = 0; i<sum+1; i++){
        if(dp[n][i]<prop) res = i;
    }

    printf("Case %d: %d\n", ++cs, res);

}

int main()
{

  //  freopen("in.txt", "r", stdin);

    int test;

    cin>>test;

    while(test--){
        solve();
    }


    return 0;
}

