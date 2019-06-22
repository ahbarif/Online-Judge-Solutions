#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

int kx[] = {+2, +1, -1, -2, -2, -1, +1, +2};
int ky[] = {+1, +2, +2, +1, -1, -2, -2, -1};
int fx[] = {+0, +0, +1, -1, -1, +1, -1, +1};
int fy[] = {-1, +1, +0, +0, +1, +1, -1, -1};


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
        int n;

        scanf("%d", &n);

        int source = 1, sink = n*2 + 2, nc = n*2 + 2;

        init();

        for(int i = 1; i<=n; i++){
            for(int j =1; j<=n; j++){
            int c;
                scanf("%d", &c);
                addEdge(i+1, j+n+1, 1, -c);
            }
        }

        for(int i = 1; i<=n; i++){
            addEdge(source, i+1, 1, 0);
            addEdge(i+n+1, sink, 1, 0);
        }

        pair<int, int> flow = MCMF(source, sink, nc);

        printf("Case %d: %d\n", ++cs, -flow.second);
    }

    return 0;
}
