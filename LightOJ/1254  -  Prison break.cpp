#include<bits/stdc++.h>
using namespace std;
 
const int sz = 105;
const int inf = 16843009;
int d[sz][sz];
int a[sz];
bool vis[sz][sz];
 
struct edge
{
    int to, cost;
 
    edge() {}
 
    edge(int to, int cost) : to(to), cost(cost) {}
};
 
vector<edge> adj[sz];
 
struct node
{
    int u, w, cap;
 
    node() {}
 
    node(int u, int w, int cap) : u(u), w(w), cap(cap) {}
 
    bool operator<(const node &p)const
    {
        return w>p.w;
    }
};
 
int dijkstra(int s, int t, int MaxCap)
{
    memset(d, 1, sizeof(d));
    memset(vis, 0, sizeof(vis));
 
    d[s][0] = 0;
    vis[s][0] = 1;
 
    priority_queue<node> q;
 
    q.push(node(s, 0, 0));
 
    while(!q.empty())
    {
 
        node top = q.top();
        q.pop();
 
        int u = top.u;
        int w = top.w;
        int cap = top.cap;
        if(u == t)  return w;
     //   if(vis[u][cap] == 1 )  continue;
        vis[u][cap] = 1;
 
        for(int i = 0; i < adj[u].size(); i++)
        {
            edge to = adj[u][i];
 
            int v = to.to;
 
            for(int j = to.cost; j<= MaxCap; j++)
            {
                int diff = 0;
 
                if(cap<j)   diff = j - cap;
 
                int add = a[u] * diff;
 
                int baki = j - to.cost;
 
                if(w + add < d[v][baki])
                {
                    d[v][baki] = w + add;
                    q.push(node(v, d[v][baki], baki));
 
                }
 
 
            }
 
        }
 
    }
 
    int res = inf;
 
    for(int i = 0; i<MaxCap; i++)   res = min(res, d[t][i]);
 
    return res;
 
}
 
void init()
{
    for(int i = 0; i<sz; i++) adj[i].clear();
}
 
int main()
{
 
    //  freopen("in.txt", "r", stdin);
 
    int test, cs = 0;
 
    scanf("%d", &test);
 
    while(test--)
    {
        init();
 
        int n, m, k, d, q, u, v, w;
 
        scanf("%d %d", &n, &m);
 
        for(int i = 0; i<n; i++)    scanf("%d", &a[i]);
 
        while(m--)
        {
            scanf("%d %d %d", &u, &v, &w);
 
            adj[u].push_back(edge(v, w));
 
            adj[v].push_back(edge(u, w));
 
        }
 
        scanf("%d", &q);
 
        printf("Case %d:\n", ++cs);
 
        while(q--)
        {
            int cap, s, t;
 
            scanf("%d %d %d", &cap, &s, &t);
 
            int res = dijkstra(s, t, cap);
 
            if(res == inf)  printf("impossible\n");
 
            else printf("%d\n", res);
 
        }
 
 
 
    }
 
    return 0;
 
}
