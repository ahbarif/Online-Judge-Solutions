#include <bits/stdc++.h>
using namespace std;

const int sz = 20005;
vector<int> g[sz];
int color[sz];
int co[5];
bool vis[sz];

void dfs(int s, int c)
{

    color[s]=c;
    int i, v;
    for(i=0; i<g[s].size(); i++)
    {
        v=g[s][i];
        if(color[v]==-1)   dfs(v, 1-c);
    }

}


void getColor(int s)
{
    co[color[s]]++;
    vis[s] = 1;
    int i, v;
    for(i=0; i<g[s].size(); i++)
    {
        v=g[s][i];
        if(vis[v]==0) getColor(v);
    }
}

void solve(int cs)
{
    for(int i=0; i<sz; i++)    g[i].clear();
    bool ok[sz];
    memset(ok, 0, sizeof ok);
    memset(color, -1, sizeof color);

    int n, i, mx = -1, res = 0;

    scanf("%d", &n);

    for(i=1; i<=n; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
        ok[x] = true;
        ok[y] = true;
        mx = max(mx, x);
        mx = max(mx, y);
    }


    for(i=1; i<=mx; i++)
    {

        if(!ok[i])  continue;
        if(color[i]==-1)
        {
            dfs(i, 0);
            memset(co, 0, sizeof co);
            memset(vis, 0, sizeof vis);
            getColor(i);
            res+=max(co[0], co[1]);
        }
    }

    printf("Case %d: %d\n", cs, res);

}

int main()
{
    int t, cs = 1;

    scanf("%d", &t);

    while(t--)
    {
        solve(cs++);
    }

    return 0;
}

