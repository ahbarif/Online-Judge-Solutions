#include<bits/stdc++.h>
using namespace std;
 
#define inf 10000000
 
int dis[1005];
 
vector<int> rev[1005];
 
struct edge
{
    int u, v, w;
 
    edge() {}
 
    edge(int u, int v, int w):u(u), v(v), w(w) {}
};
 
vector<edge> E;
set<int> st;
 
bool vis[1005];
 
void dfs(int u)
{
    st.insert(u);
    vis[u] = true;
 
    for(int i = 0; i<rev[u].size(); i++)
    {
        int v = rev[u][i];
 
        if(vis[v]==0) dfs(v);
    }
 
}
 
void bellman_ford(int source, int n)
{
    for(int i=0; i<1005; i++)   dis[i] = inf;
 
    dis[source] = 0;
 
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<E.size(); j++)
        {
            int u = E[j].u;
            int v = E[j].v;
            int w = E[j].w;
 
            if(dis[u] + w < dis[v]  && dis[u]!=inf)
            {
                dis[v] = dis[u] + w;
            }
        }
    }
 
    for(int j=0; j<E.size(); j++)
    {
        int u = E[j].u;
        int v = E[j].v;
        int w = E[j].w;
 
        if(dis[u] + w < dis[v] && dis[u]!=inf)
        {
            if(vis[v]==0) dfs(v);
 
        }
    }
 
    return;
 
}
 
int main()
{
 
    int test, cs = 0;
 
    scanf("%d", &test);
 
    while(test--)
    {
 
        int n, m, z, x, y;
 
        scanf("%d %d", &n, &m);
 
        E.clear();
 
        for(int i = 0; i<1005; i++) rev[i].clear();
 
        while(m--)
        {
            scanf("%d %d %d", &x, &y, &z);
            rev[y].push_back(x);
            E.push_back(edge(y, x, z));
        }
 
        for(int i = 0; i<n; i++)
        {
            E.push_back(edge(n, i, 0));
        }
 
        printf("Case %d:", ++cs);
 
        bellman_ford(n, n+1);
 
        if(st.size()==0)
        {
            puts(" impossible");
            continue;
        }
        for(set<int> ::iterator it = st.begin(); it!= st.end(); it++)
        {
            printf(" %d", *it);
        }
 
        puts("");
 
        st.clear();
        memset(vis, 0, sizeof(vis));
 
    }
 
    return 0;
}
 
