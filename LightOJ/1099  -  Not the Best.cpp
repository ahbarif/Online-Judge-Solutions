#include<bits/stdc++.h>
using namespace std;
 
const int sz = 5005;
const int inf = 16843009;
int d[sz][2];
 
struct edge
{
    int to, cost;
 
    edge() {}
 
    edge(int to, int cost):to(to), cost(cost) {}
};
 
vector<edge> adj[sz];
 
struct node
{
    int u, w, t;
 
    node() {}
 
    node(int u, int w, int t) : u(u), w(w), t(t) {}
 
    bool operator<(const node &p)const
    {
        return w>p.w;
    }
};
 
int dijkstra(int n)
{
    memset(d, 1, sizeof(d));
 
    d[1][0] = 0;
 
    priority_queue<node> q;
 
    q.push(node(1, 0, 0));
 
    while(!q.empty())
    {
 
        node top = q.top();
        q.pop();
 
        int u = top.u;
        int w = top.w;
        int t = top.t;
 
        if(w > d[u][t]) continue;
 
        for(int i = 0; i < adj[u].size(); ++i)
        {
            int to = adj[u][i].to;
 
            int w_extra = adj[u][i].cost;
 
            if(w + w_extra < d[to][0])
            {
                d[to][1] = d[to][0];
                d[to][0] = w + w_extra;
                q.push(node(to, d[to][1], 1));
                q.push(node(to, d[to][0], 0));
 
            }
            else if(w + w_extra > d[to][0] and w + w_extra < d[to][1])
            {
                d[to][1] = w + w_extra;
                q.push(node(to, d[to][1], 1));
            }
        }
 
    }
 
    return inf;
}
 
void init()
{
    for(int i = 0; i<sz; i++) adj[i].clear();
 
}
 
int main()
{
 
   // freopen("in.txt", "r", stdin);
 
    int test, cs = 0;
 
    scanf("%d", &test);
 
    while(test--)
    {
        init();
 
        int n, m, u, v, w;
 
        scanf("%d %d", &n, &m);
 
        while(m--)
        {
            scanf("%d %d %d", &u, &v, &w);
 
            adj[u].push_back(edge(v, w));
            adj[v].push_back(edge(u, w));
 
        }
 
        dijkstra(n);
 
        printf("Case %d: %d\n",++cs, d[n][1]);
 
 
    }
 
 
 
}
