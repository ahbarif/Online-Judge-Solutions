#include<bits/stdc++.h>
using namespace std;

int dp[105][105], a[105], sum[105], n;

int getsum(int i, int j)
{
    return sum[j] - sum[i-1];
}

void init()
{
    memset(sum, 0, sizeof(sum));

    for(int i=0; i<105; i++)
    {
        for(int j=0; j<105; j++)
        {
            dp[i][j] = INT_MIN;
        }
    }
}

int f(int i, int j)
{
        if(i>j) return 0;

        if(dp[i][j]!=INT_MIN)    return dp[i][j];

        int res = INT_MIN;

        for(int x = i; x<=j; x++)
        {
                int tmp = getsum(i, x) - f(x+1, j);

                res = max(res, tmp);
        }

        for(int x = j; x>=i; x--)
        {
                int tmp = getsum(x, j) - f(i, x-1);

                res = max(res, tmp);
        }

        return dp[i][j] = res;



}

int main()
{

    while(scanf("%d", &n)!=EOF)
    {
        if(n==0) break;

        init();

        for(int i=1; i<=n; i++) scanf("%d", &a[i]);

        for(int i=1; i<=n; i++) sum[i] = sum[i-1] + a[i];

        int res = f(1, n);

        printf("%d\n", res);
    }

    return 0;

}
