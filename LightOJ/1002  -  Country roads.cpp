#include <bits/stdc++.h>
using namespace std;

vector<int> g[505], cost[505];
int par[505];

bool vis[505];
int dis[505];

void bfs(int src, int mx)
{
    memset(vis, 0, sizeof vis);
    memset(dis, -1, sizeof dis);

    dis[src] = mx;

    queue<int> q;
    q.push(src);
    vis[src] = 1;

    while(!q.empty())
    {
        int top = q.front();
        q.pop();

        for(int i = 0; i<g[top].size(); i++)
        {
            int u = g[top][i];
            int c = cost[top][i];

            if(vis[u]==0)
            {
                q.push(u);
                dis[u] = max(dis[top], c);
                vis[u] = 1;
            }
        }
    }

}

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

    bool operator<(const edge &p)const
    {
        return w<p.w;
    }
};


void makeset(int n)
{
    par[n] = n;
}

int find_par(int n)
{
    if (par[n]==n) return n;
    par[n]=find_par(par[n]);
    return par[n];
}

void union_(int x, int y)
{
    int u = find_par(x);
    int v = find_par(y);

    if(u==v)    return;
    par[u] = v;
}

int main()
{

    vector<edge> E;
    int n, m, x, y, z, i, test, cs=1, mycity;

    scanf("%d", &test);

    while(test--)
    {

        for(i=0; i<505; i++)    makeset(i), g[i].clear(), cost[i].clear();
        E.clear();

        scanf("%d %d", &n, &m);

        for(i=0; i<m; i++)
        {
            scanf("%d %d %d", &x, &y, &z);

            E.push_back(edge(x, y, z));
        }

        sort(E.begin(), E.end());

        for(i=0; i<E.size(); i++)
        {
            x = E[i].u;
            y = E[i].v;
            z = E[i].w;

            if(find_par(x)==find_par(y))    continue;

            else
            {
                union_(x, y);
                g[x].push_back(y);
                g[y].push_back(x);
                cost[x].push_back(z);
                cost[y].push_back(z);
            }
        }

        scanf("%d", &mycity);


        bfs(mycity, 0);

        printf("Case %d:\n", cs++);

        for(i=0; i<n; i++)   printf(dis[i]==-1?"Impossible\n":"%d\n", dis[i]);

    }

    return 0;
}