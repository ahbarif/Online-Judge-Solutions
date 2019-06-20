#include <bits/stdc++.h>
using namespace std;

const long long mod = 1000000007LL;

template<typename T> inline T bigmod(T a, T b)
{
    T ans = 1;

    while(b)
    {
        if(b&1) ans = (ans*a)%mod;
        a = (a*a)%mod;
        b = b>>1;
    }
    return ans%mod;
}

long long child[1005];


long long dp[1005][1005];

long long fac[1005];

long long nCr(long long n, long long r)
{

    if(n == r || r == 0)    return 1;

    else if(r == 1)   return n;

    if(dp[n][r]!=-1)    return dp[n][r];

    long long x = nCr(n-1, r)%mod;
    long long y = nCr(n-1, r-1)%mod;

    return dp[n][r] = (x+y)%mod;

}

vector<int> adj[1005];

long long res;

bool vis[1005];

void dfs(int u)
{
    vis[u] = 1;

    child[u] = 1;

    for(int i =0; i<adj[u].size(); i++)
    {
        int v = adj[u][i];

        if(vis[v]==0)
        {
            dfs(v);
            child[u] += child[v];
        }
    }

    long long sum = child[u] - 1;

    for(int i = 0; i<adj[u].size(); i++)
    {
        long long v = child[adj[u][i]];

        long long tmp = nCr(sum, v);

        sum-=v;

        res = (res*tmp)%mod;
    }

}

int main()
{

    memset(dp, -1, sizeof(dp));

    int test, cs = 0;

    scanf("%d", &test);

    while(test--)
    {
        memset(child, 0, sizeof(child));

        for(int i = 0; i<1005; i++) adj[i].clear();

        int n, m, u, v;

        scanf("%d", &n);

        memset(vis, 0, sizeof(vis));

        for(int i = 0; i<n-1; i++)
        {
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
            vis[v] = true;
        }

        res = 1LL;

        for(int i = 1; i<=n; i++)
        {

            if(!vis[i])
            {
                memset(vis, 0, sizeof(vis));
                dfs(i);
            }
        }

        printf("Case %d: %lld\n", ++cs, res);
    }
}
