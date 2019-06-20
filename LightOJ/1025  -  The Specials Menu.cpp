#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

char s[62];

ll dp[62][62];

ll f(int i, int j)
{
    if(i>j)     return 0;

    if(i==j)    return 1;

    if(dp[i][j]!=-1)    return dp[i][j];

    ll res = 0;

    if(s[i]==s[j])  res = 1 + f(i+1, j) + f(i, j-1);

    else res = f(i+1, j) + f(i, j-1) - f(i+1, j-1);

    return dp[i][j] = res;

}

int main()
{

        int test, cs = 0;

        scanf("%d", &test);

        while(test--)
        {

           memset(dp, -1, sizeof(dp));

           scanf("%s", &s);

           ll res = f(0, strlen(s)-1);

           printf("Case %d: %lld\n", ++cs, res);

        }

        return 0;

}
