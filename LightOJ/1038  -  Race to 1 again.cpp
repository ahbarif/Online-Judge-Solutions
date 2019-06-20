#include <bits/stdc++.h>
using namespace std;

double dp[100005];
bool vis[100005];

double f(int n)
{
    if(n==1)    return 0.0;

    if(vis[n])   return dp[n];

    vis[n] = true;

    int sz = 0;
    double res = 0;

    for(int i = 1; i*i<=n; i++)
    {
        if(n%i==0)
        {
            res = res + f(i);
            sz++;

            if(i!=n/i)
            {
                res = res + f(n/i);
                sz++;
            }
        }
    }

    double hor = sz*1.0;

    res = (res + hor)/(hor-1.0);

    return dp[n] = res;

}

int main()
{


        int test, cs = 0;

        scanf("%d", &test);

        while(test--)
        {
            int n;

            scanf("%d", &n);

            printf("Case %d: %.8lf\n", ++cs, f(n));
        }

}
