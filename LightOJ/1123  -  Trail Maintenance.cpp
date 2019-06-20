#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

int par[205];

struct edge
{
    int u, v, w;

    edge() {}
    edge(int _u, int _v, int _w)
    {
        u = _u;
        v = _v;
        w = _w;
    }

} E[6006];

vector<int> g[205];

bool vis[205];

void dfs(int u)
{
    vis[u] = true;

    int sz = g[u].size();

    for(int i = 0; i<sz; i++)
    {
        int v = g[u][i];

        if(vis[v]==false)   dfs(v);
    }
}

void makeset()
{
    for(int i=0; i<205; i++)    par[i] = i;
    memset(vis, 0, sizeof(vis));
}

int find_par(int n)
{
    if (par[n]==n) return n;
    par[n]=find_par(par[n]);
    return par[n];
}

void Merge(int x, int y)
{
    int u = find_par(x);
    int v = find_par(y);

    if(u==v)    return;
    par[u] = v;
}

int f(int n, int nodes)
{

    int x, y, z, cost = 0;

    makeset();

    for(int i=1; i<=n; i++)
    {
        x = E[i].u;
        y = E[i].v;
        z = E[i].w;

        if(find_par(x)==find_par(y))    continue;

        else
        {
            Merge(x, y);
            cost += z;
        }
    }

    dfs(1);

    for(int i = 1; i<=nodes; i++)
    {
        if(vis[i]==0)   return -1;
    }

    return cost;
}


int main()
{


    int n, m, test, cs = 0;

    scanf("%d", &test);

    E[1].w = -1;

    while(test--)
    {

        for(int i = 0; i<205; i++)  g[i].clear();

        scanf("%d %d", &n, &m);

        int res = 0, idx = 0;

        printf("Case %d:\n", ++cs);

        while(m--)
        {
            edge e;

            scanf("%d %d %d", &e.u, &e.v, &e.w);
            g[e.u].push_back(e.v);
            g[e.v].push_back(e.u);

            for(int i = idx; i>=0; i--)
            {
                if(E[i].w > e.w)  E[i+1] = E[i];

                else
                {
                    E[i+1] = e;
                    break;
                }
            }
            idx++;

            printf("%d\n", f(idx, n));

        }


    }

    return 0;
}

