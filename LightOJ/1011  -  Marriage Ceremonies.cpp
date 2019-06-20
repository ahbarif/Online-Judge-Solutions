#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> inline bool isOn(T n, T pos)
{
    return (bool)(n&(1<<pos));
}

ll dp[18][(1<<16)+5];
int a[20][20], n;

ll foo(int i, int mask)
{
    if(i>n) return 0;

    if(dp[i][mask]!=-1) return dp[i][mask];

    ll ret = 0;

    for(int j = 1; j<=n; j++)
    {
        if(isOn(mask, j)==true) continue;

        ll tmp = foo(i+1, (mask|(1<<j)));

        ret = max(ret, a[i][j]+tmp);
    }

    return dp[i][mask] = ret;
}

int main()
{
		int test, cs = 1;

		scanf("%d", &test);

		while(test--)
		{
			int i, j;

			scanf("%d", &n);

			for(i=1; i<=n; i++)
			{
				for(j=1; j<=n; j++)	scanf("%d", &a[i][j]);
			}

			memset(dp, -1, sizeof(dp));

			ll res = foo(1, 0);

			printf("Case %d: %lld\n", cs++, res);


		}

		return 0;
}
