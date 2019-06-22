#include<bits/stdc++.h>
using namespace std;

const int maxn = 500005;
const int maxn2 = 500005;

vector <int> adj[maxn];
bool vis[maxn];
int Left[maxn], Right[maxn];

int primes[maxn2], pid = 0;
bool mark[maxn2];
int divs[maxn], a[maxn], idx[maxn2];

bool dfs(int u)
{
    if(vis[u]) return false;
    vis[u] = true;
    int len = adj[u].size(), i, v;
    for(i=0; i<len; i++)
    {
        v = adj[u][i];
        if(Right[v]==-1)
        {
            Right[v] = u, Left[u] = v;
            return true;
        }
    }
    for(i=0; i<len; i++)
    {
        v = adj[u][i];
        if(dfs(Right[v]))
        {
            Right[v] = u, Left[u] = v;
            return true;
        }
    }
    return false;
}

int match(int n)
{

    int i, ret = 0;
    bool done;

    memset(Left, -1, sizeof(Left));
    memset(Right, -1, sizeof(Right));

    do
    {
        //  puts("#");
        done = true;

        memset(vis, 0, sizeof(vis));

        for(i=1; i<=n; i++)
        {
            if(Left[i]==-1 && dfs(i))
            {
                done = false;
            }
        }
    }
    while(!done);

    for(i=1; i<=n; i++) ret += (Left[i]!=-1);

    return ret;
}


void sieve(int N)
{

    primes[pid++] = 2;

    for(int i = 4; i<=N; i+=2)
    {
        mark[i] = true;
    }

    for(int i = 3; i<=N; i+=2)
    {
        if(mark[i] == false)
        {
            primes[pid++] = i;
            for(int j = 2*i; j<=N; j+=i)
            {
                mark[j] = true;
            }
        }
    }

    for(int i = 1; i<=500000; i++)
    {
        int x = i;
        int ans = 0;

        for(int j = 0; primes[j]*primes[j] <= x; j++)
        {
            if(x%primes[j] == 0)
            {
                while(x%primes[j] == 0)
                {
                    x /= primes[j];
                    ans ^=1;
                }
            }
        }

        if(x > 1) ans ^= 1;
        divs[i] = ans;
    }
}

void solve(int cs)
{

    for(int i = 0; i<maxn; i++) adj[i].clear();

    memset(idx, -1, sizeof(idx));

    int n, mx = 0;

    scanf("%d", &n);

    for(int i = 1; i<=n; i++)
    {
        scanf("%d", &a[i]);
        idx[a[i]] = i;
        mx = max(mx, a[i]);
    }

    for(int i = 1; i<=n; i++)
    {

        int u = a[i];

        for(int j = 0; j<pid; j++)
        {

            int k = primes[j];

            int tmp = u*k;

            if(tmp>mx) break;

            if(divs[u] == 0)
            {
                adj[i].push_back(idx[tmp]);
            }
            else
            {
                adj[idx[tmp]].push_back(i);
            }

        }
    }

    printf("Case %d: %d\n", cs, n-match(n));

    return;

}

int main()
{
    sieve(500000);

    int test, cs = 0;

    scanf("%d", &test);

    while(test--)
    {
        solve(++cs);

    }

    return 0;


}

