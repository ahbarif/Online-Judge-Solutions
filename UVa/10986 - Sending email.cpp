#include<bits/stdc++.h>
using namespace std;

const int mx = 100005;
const int inf = 16843009;

struct node
{

    int u, w;

    node() {}

    node(int u, int w) : u(u), w(w) {}

    bool operator<(const node &p)const
    {
        return w>p.w;
    }
};

int par[mx], dis[mx];

vector<int> graph[mx], cost[mx];

int dijkstra(int src)   // single source shortest path
{
    memset(dis, 1, sizeof(dis));
    dis[src] = 0;
    memset(par, -1, sizeof(par));

    priority_queue<node> q;

    q.push(node(src, 0));

    while(!q.empty())
    {
        node top=q.top();

        q.pop();

        int u = top.u;

        for(int i=0; i<graph[u].size(); i++)
        {
            int v = graph[u][i];

            if(dis[v] > dis[u] + cost[u][i])
            {
                dis[v] = dis[u] + cost[u][i];
                par[v] = u;
                q.push(node(v, dis[v]));
            }
        }

    }

}

void init()
{
    for(int i = 0; i<mx; i++)
    {
        graph[i].clear();
        cost[i].clear();
    }
}

int main()
{

    int test, cs = 0;

    scanf("%d", &test);

    while(test--)
    {
        init();

        int n, m, src, dst;

        scanf("%d %d %d %d", &n, &m, &src, &dst);

        while(m--)
        {
            int u, v, w;

            scanf("%d %d %d", &u, &v, &w);

            graph[u].push_back(v);
            graph[v].push_back(u);

            cost[u].push_back(w);
            cost[v].push_back(w);

        }
        dijkstra(src);

        printf("Case #%d: ", ++cs);

        if(dis[dst] == inf) puts("unreachable");
        else cout<<dis[dst]<<endl;
    }

}
