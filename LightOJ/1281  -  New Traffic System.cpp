#include<bits/stdc++.h>
using namespace std;
 
const int sz = 10005;
const int inf = 16843009;
int d[sz][11];
 
struct edge
{
    int to, cost, type;
 
    edge() {}
 
    edge(int to, int cost, int type) : to(to), cost(cost), type(type) {}
};
 
vector<edge> adj[sz];
 
struct node
{
    int u, w, used;
 
    node() {}
 
    node(int u, int w, int used) : u(u), w(w), used(used) {}
 
    bool operator<(const node &p)const
    {
        return w>p.w;
    }
};
 
int dijkstra(int n, int lm)
{
 
    d[0][0] = 0;
 
    priority_queue<node> q;
 
    q.push(node(0, 0, 0));
 
    while(!q.empty())
    {
 
        node top = q.top();
        q.pop();
 
        int u = top.u;
        int w = top.w;
        int used = top.used;
 
        for(int i = 0; i < adj[u].size(); i++)
        {
            edge to = adj[u][i];
 
            int v = to.to;
            int prop = used + to.type;
 
            if(prop <= lm && w + to.cost < d[v][prop])
            {
                d[v][prop] = w + to.cost;
                q.push(node(v, d[v][prop], prop));
            }
 
        }
 
    }
 
    int res = inf;
 
    for(int i = 0; i<11; i++)   res = min(res, d[n-1][i]);
 
    return res;
 
}
 
void init()
{
    for(int i = 0; i<sz; i++) adj[i].clear();
 
    memset(d, 1, sizeof(d));
 
}
 
int main()
{
 
    // freopen("in.txt", "r", stdin);
 
    int test, cs = 0;
 
    scanf("%d", &test);
 
    while(test--)
    {
        init();
 
        int n, m, k, d, u, v, w;
 
        scanf("%d %d", &n, &m);
 
        scanf("%d %d", &k, &d);
 
        while(m--)
        {
            scanf("%d %d %d", &u, &v, &w);
 
            adj[u].push_back(edge(v, w, 0));
 
        }
 
        while(k--)
        {
            scanf("%d %d %d", &u, &v, &w);
 
            adj[u].push_back(edge(v, w, 1));
 
        }
 
        int res = dijkstra(n, d);
 
        if(res == inf)  printf("Case %d: Impossible\n",++cs);
 
        else printf("Case %d: %d\n",++cs, res);
 
    }
 
    return 0;
 
}
 
