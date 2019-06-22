#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int maxn = 105, inf = 16843009;

struct edge
{

    int u, v, cap, cost;

    int next;

    edge() {}

    edge(int u, int v, int cap, int cost, int next) : u(u),v(v),cap(cap),cost(cost),next(next) {}

} Edge[100005];

int NE, head[maxn], dist[maxn], par[maxn];
bool vis[maxn];

inline void init()
{
    NE = 0;
    memset(head, -1, sizeof(head));
}

inline void addEdge(int u, int v, int cap, int cost)   // directed edges only
{
    Edge[NE] = edge(u, v, cap, cost, head[u]);
    head[u] = NE++;
    Edge[NE] = edge(v, u, 0, -cost, head[v]);
    head[v] = NE++;
}


inline bool SPFA(int s, int t, int n)
{
    int i, u, v;

    memset(vis, 0, sizeof(vis));
    memset(par, -1, sizeof(par));
    memset(dist, 1, sizeof(dist));


    vis[s] = true;
    dist[s] = 0;

    queue<int> q;
    q.push(s);

    while(!q.empty())
    {
        int u  = q.front();
        q.pop();

        vis[u] = false;


        for(i = head[u]; ~ i; i = Edge[i].next)
        {
            v = Edge[i].v;

            int tmp = dist[u] + Edge[i].cost;

            if(Edge[i].cap &&  dist[v] > tmp)
            {
                dist[v] = tmp;
                par[v] = i;
                if(!vis[v])
                {
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
    }

    if(dist[t] == inf) return false;
    return true;
}

pii MCMF(int s, int t, int n)
{
    int flow = 0, i, minflow, mincost=0;

    while(SPFA(s, t, n))
    {
        // cout<<"#"<<endl;
        minflow = inf;

        for(i = par[t]; ~i ; i = par[Edge[i].u])
        {
            minflow = min(minflow, Edge[i].cap);
        }
        flow += minflow;
        for(i = par[t]; ~i; i = par[Edge[i].u])
        {
            Edge[i].cap -= minflow;
            Edge[i^1].cap += minflow;
        }
        mincost += dist[t] * minflow;
    }
    return make_pair(flow, mincost);
}


int main()
{


    int test, cs = 0;

    scanf("%d", &test);

    while(test--)
    {
        int n, m, p;

        scanf("%d %d %d", &n, &m, &p);

        int source = 0, sink = n, nc = n;

        init();

        addEdge(source, 1, p, 0);

        while(m--)
        {

            int u, v, cost, cap;

          //  cin>>u>>v>>cost>>cap;
            cin>>u>>v>>cap>>cost;

            addEdge(u, v, cap, cost);
            addEdge(v, u, cap, cost);

        }


        pair<int, int> flow = MCMF(source, sink, nc);

      //  cout<<"flow = "<<flow.first<<endl;

        if(flow.first<p)  printf("Case %d: impossible\n", ++cs, -flow.second);

        else printf("Case %d: %d\n", ++cs, flow.second);
    }

    return 0;
}
