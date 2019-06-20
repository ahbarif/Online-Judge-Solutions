#include<bits/stdc++.h>
using namespace std;

const int maxn = 100;

int dp[maxn+5][maxn+5][maxn+5];

int a[maxn+5][maxn+5];

int n, m;

int foo(int row1, int c1, int c2){

    if(row1 == n && c1==m) return a[row1][c1];

    if(row1>n || c1>m || c2>m) return 0;

    int &res = dp[row1][c1][c2];

    if(res != -1) return res;

    res = 0;

    int row2 = row1+c1-c2;

    if(row1 == row2 && c1 == c2) return 0;

    res = max(res, foo(row1+1, c1, c2));
    res = max(res, foo(row1+1, c1, c2+1));
    res = max(res, foo(row1, c1+1, c2));
    res = max(res, foo(row1, c1+1, c2+1));

    res = res + a[row1][c1] + a[row2][c2];

    return res;




}
int main()
{

    int test, cs = 0;

    scanf("%d", &test);

    while(test--)
    {
        memset(a, 0, sizeof(a));

        scanf("%d %d", &n, &m);

        for(int i = 1; i<=n; i++)
        {
            for(int j = 1; j<=m; j++)
            {
                scanf("%d", &a[i][j]);
            }
        }

        memset(dp, -1, sizeof(dp));

        int res = foo(1, 1, 2);

        printf("Case %d: %d\n", ++cs, res);

    }

    return 0;
}

