#include<bits/stdc++.h>
using namespace std;

int combination[1005][1005];

int dp[1005];

int nCr(int n, int r)
{

    if(n == r || r == 0)    return 1;

    else if(r == 1)   return n;

    if(combination[n][r]!=-1)    return combination[n][r];

    int res1 = nCr(n-1, r)%10056;
    int res2 = nCr(n-1, r-1)%10056;

    return combination[n][r] = (res1+res2)%10056;

}

int f(int n)
{

    if(n==0)    return 1;

    if(dp[n]!=-1) return dp[n];

    int res = 0;

    for(int i=1; i<=n; i++)
    {
        res = res + nCr(n, i) * f(n-i);
        res%=10056;

    }

    return dp[n] = res;
}


int main()
{

    memset(combination, -1, sizeof(combination));

    memset(dp, -1, sizeof(dp));

    int test, cs = 0;

    scanf("%d", &test);

    while(test--)
    {
        int n;

        scanf("%d", &n);

        printf("Case %d: %d\n", ++cs, f(n));
    }

    return 0;

}
