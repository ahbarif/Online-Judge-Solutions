#include <bits/stdc++.h>
using namespace std;

double a[105];
double dp[105];
double vis[105];
int n;

double f(int x)
{

    if(x==n)    return a[n];

    if(vis[x])   return dp[x];

    vis[x] = true;

    double den = 6.0, res = 0.0;

    for(int i = x+1; i<=x+6; i++)
    {
        if(i>n) den--;
        else
        {
            res = res + f(i) + a[x];
        }
    }

    res/=den;

    return dp[x] = res;

}

int main()
{


        int test, cs = 0;

        scanf("%d", &test);

        while(test--)
        {
            memset(vis, 0, sizeof(vis));

            scanf("%d", &n);

            for(int i = 1; i<=n; i++)   scanf("%lf", &a[i]);

            printf("Case %d: %.8lf\n", ++cs, f(1));
        }


}
