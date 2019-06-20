#include <bits/stdc++.h>
using namespace std;

const int sz = 10005;

vector<int> g[sz];
bool vis[sz], ap[sz];
int low[sz], par[sz], dis[sz], timer = 0;

void init()
{
    memset(vis, 0, sizeof vis);
    memset(par, -1, sizeof par);
    memset(ap, 0, sizeof ap);
    timer = 0;
    for(int i=0; i<sz; i++) g[i].clear();
}

void dfs(int v)
{
    vis[v] = true;
    low[v] = dis[v] = ++timer;

    int u, subtree = 0, i;

    for(i=0; i<g[v].size(); i++)
    {
        u = g[v][i];

        if(vis[u]==false)
        {
            subtree++;
            par[u] = v;
            dfs(u);

            low[v] = min(low[v], low[u]);

            if(par[v]!=-1 && low[u]>=dis[v])    ap[v] = true;
            if(par[v]==-1 && subtree>1) ap[v] = true;
        }

        else if(u!=par[v])  low[v]=min(low[v],dis[u]);
    }
}


int main()
{
        int test, cs = 1;

        scanf("%d", &test);

        while(test--)
        {
            int n, m, x, y, i, res = 0;

            init();

            scanf("%d %d", &n, &m);

            while(m--)
            {
                scanf("%d %d", &x, &y);
                g[x].push_back(y);
                g[y].push_back(x);
            }

            dfs(1);

            for(i=0; i<=n; i++)
                if(ap[i])   ++res;

            printf("Case %d: %d\n", cs++, res);

        }

        return 0;

}

