#include<bits/stdc++.h>
using namespace std;

const int maxn = 105;

int dp[maxn][maxn];
int a[maxn];

int foo(int i, int j)
{
 //   cout<<i<<" "<<j<<endl;

    if(i>j) return 0;
    if(i==j) return 1;

    int &res = dp[i][j];

    if(res != -1) return res;

    res = 1 + foo(i+1, j);

    for(int k = i+1; k<=j; k++)
    {
            int temp = 1010;
            if(a[i]==a[k]) temp = foo(i, k-1) + foo(k+1, j);
            res = min(res, temp);
    }

 //   cout<<res<<endl;

    return res;
}

int main()
{

    int test, cs = 0;

    scanf("%d", &test);

    while(test--)
    {


        int n;

        scanf("%d", &n);

        for(int i = 1; i<=n; i++) scanf("%d", &a[i]);

        memset(dp, -1, sizeof(dp));

        int res = foo(1, n);

        printf("Case %d: %d\n", ++cs, res);


    }

    return 0;


}

