#include<bits/stdc++.h>
using namespace std;
 
const int sz = 10005;
 
typedef pair<int, int> pii;
 
vector<int> adj[sz];
 
bool vis[sz];
int cid[sz], low[sz], dis[sz], timer = 0, cp, deg[sz];
set<pii> st;
 
void init()
{
 
    st.clear();
    timer = 0;
    cp = 0;
    for(int i = 0; i<sz; i++)   adj[i].clear();
    memset(vis, 0, sizeof(vis));
 
}
 
void dfs_bridge(int u, int par)
{
    vis[u] = true;
 
    low[u] = dis[u] = ++timer;
 
    for(vector<int> ::iterator it = adj[u].begin(); it!= adj[u].end(); it++)
    {
        int v = *it;
 
        if(vis[v] == false)
        {
            dfs_bridge(v, u);
 
            low[u] = min(low[v], low[u]);
 
            if(low[v]>dis[u]) st.insert(make_pair(min(u, v), max(u, v)));
        }
 
        else if(v!=par)  low[u] = min(low[u],dis[v]);
    }
}
 
void dfs(int u)
{
    vis[u] = true;
    cid[u] = cp;
 
    for(int i=0; i<adj[u].size(); i++)
    {
        int v = adj[u][i];
 
        pii tmp = make_pair( min(u,v),max(u,v) );
 
        if(st.count(tmp)) continue;
 
        if(vis[v] ==false) dfs(v);
 
    }
}
int main()
{
    int test, cs = 0;
 
    scanf("%d", &test);
 
    while(test--)
    {
        init();
        int n, m, u, v, i, j, res = 1;
 
        scanf("%d %d", &n, &m);
 
        while(m--)
        {
            scanf("%d %d", &u, &v);
 
            adj[u].push_back(v);
 
            adj[v].push_back(u);
        }
 
        for(int i=0; i<n; i++)
        {
            if(!vis[i]) dfs_bridge(i, -1);
        }
 
        memset(vis, 0, sizeof(vis));
 
        for(int i = 0; i<n; i++)
        {
            if(vis[i]==false)
            {
                ++cp;
                dfs(i);
            }
        }
 
        memset(deg, 0, sizeof(deg));
 
        for(set<pii>:: iterator it = st.begin(); it!= st.end(); it++)
        {
            pii tmp=(*it);
 
            deg[cid[tmp.first]]++;
            deg[cid[tmp.second]]++;
        }
 
        for(int i = 0; i<=cp; i++)  if(deg[i]==1)   ++res;
 
        printf("Case %d: %d\n", ++cs, res/2);
 
    }
 
    return 0;
 
}
