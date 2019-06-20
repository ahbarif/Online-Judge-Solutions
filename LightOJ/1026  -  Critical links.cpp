#include <bits/stdc++.h>
using namespace std;

const int sz = 10005;

vector<int> g[sz];
bool vis[sz];
int low[sz], dis[sz], timer = 0;
set<pair<int, int> > st;
set<pair<int, int> > ::iterator it;

void init()
{
    memset(vis, 0, sizeof vis);
    timer = 0;
    for(int i=0; i<sz; i++) g[i].clear();
    st.clear();
}
void dfs(int u, int par)
{
    vis[u] = true;
    low[u] = dis[u] = ++timer;


    for(int i=0; i<g[u].size(); i++)
    {
        int v = g[u][i];

        if(vis[v]==false)
        {
            dfs(v, u);

            low[u] = min(low[v], low[u]);

            if(low[v]>dis[u])
            {
                int x = max(u, v);
                int y = min(u, v);
                st.insert(make_pair(y, x));
            }
        }

        else if(v!=par)  low[u]=min(low[u],dis[v]);
    }
}

int main()
{

    int t, cs = 0;

    scanf("%d", &t);

    while(t--)
    {

        int n, m, x, y, i, j;

        scanf("%d", &n);

        init();

        for(i=0; i<n; i++)
        {
            scanf("%d (%d)", &x, &m);

            for(j=0; j<m; j++)
            {
                scanf("%d", &y);
                g[x].push_back(y);
            }
        }

        for(int i=0; i<n; i++)
        {
            if(!vis[i]) dfs(i, -1);
        }

        printf("Case %d:\n%d critical links\n", ++cs, st.size());

        for(it = st.begin(); it!=st.end(); it++)
        {
            printf("%d - %d\n", it->first, it->second);
        }
    }

    return 0;

}
