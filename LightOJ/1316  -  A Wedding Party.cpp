#include<bits/stdc++.h>
using namespace std;
 
const int sz = 505, inf = 16843009, mx = 1<<17;
 
vector<int> adj[sz], cost[sz];
 
int n, m, s, dis[20][sz], shop[20];
 
int dp[mx][20], cp[mx][20], total;
 
struct node{
    int u, w;
 
    node(int u, int w): u(u), w(w){}
 
    bool operator<(const node &p) const{
        return w>p.w;
    }
};
 
void init()
{
    for(int i = 0; i<sz; i++)
    {
        adj[i].clear();
        cost[i].clear();
    }
 
    memset(dp, -1, sizeof(dp));
    memset(cp, -1, sizeof(cp));
    memset(dis, 1, sizeof(dis));
 
}
 
void dijkstra(int src, int id)
{
 
    dis[id][src] = 0;
 
    priority_queue<node> q;
 
    q.push(node(src, 0));
 
    while(!q.empty())
    {
        node top = q.top();
 
        int u = top.u;
        int c = top.w;
 
        q.pop();
 
        for(int i=0; i<adj[u].size(); i++)
        {
            int v = adj[u][i];
            int w = cost[u][i];
 
            if(dis[id][v] > c + w)
            {
                dis[id][v] = c + w;
 
                q.push(node(v, c+w));
            }
        }
    }
}
 
int tot(int mask, int cur)  // koyta
{
 
    int &ret = dp[mask][cur];
 
    if(ret != -1)   return ret;
 
    ret = 0;
 
    for(int i = 1; i<=s; i++)
    {
        if(((mask&(1<<i)) == 0) && dis[cur][shop[i]] != inf)
        {
 
            int tmp = tot(mask|(1<<i), i);
            ret = max(ret, tmp);
        }
    }
 
    if(dis[cur][n-1] != inf) ret = max(ret, __builtin_popcount(mask));
 
    return ret;
 
}
 
int foo(int mask, int cur)
{
 
    int &ret = cp[mask][cur];
 
    if(ret != -1)   return ret;
 
    ret = inf;
 
    for(int i = 1; i<=s; i++)
    {
        if((mask&(1<<i)) == 0 && dis[cur][shop[i]] != inf)
        {
            int tmp = dis[cur][shop[i]] + foo(mask|(1<<i), i);
            ret = min(ret, tmp);
        }
    }
 
    if((dis[cur][n-1] != inf) && __builtin_popcount(mask) == total )
    {
        ret = min (ret, dis[cur][n-1]);
    }
 
    return ret;
}
 
int main()
{
 
  //  freopen("in.txt", "r", stdin);
 
    int test, cs = 0;
 
    scanf("%d", &test);
 
    while(test--)
    {
        init();
 
        scanf("%d %d %d", &n, &m, &s);
 
        for(int i = 1; i<=s; i++)   scanf("%d", &shop[i]);
 
        while(m--)
        {
            int u, v, w;
 
            scanf("%d %d %d", &u, &v, &w);
 
            adj[u].push_back(v);
            cost[u].push_back(w);
 
        }
 
        dijkstra(0, 0);
 
        for(int i = 1; i<=s; i++)   dijkstra(shop[i], i);
 
        total = tot(0, 0);
 
        int res = foo(0, 0);
 
        printf("Case %d: ", ++cs);
 
        if(total == 0)  puts("Impossible");
 
        else
        {
            printf("%d %d\n", total, res);
        }
 
    }
 
    return 0;
}
