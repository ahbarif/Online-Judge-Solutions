#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

int fx[] = {+0, +0, +1, -1};
int fy[] = {-1, +1, +0, +0};

map<pair<int, int>, int  > mp;


const int maxn = 1005, inf = 16843009;


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
      //  cout<<"#"<<endl;
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

char grid[35][35];

bool valid(int x, int y, int n, int m){
    return (x>=0 && x<n && y>=0 && y<m && grid[x][y] != '#');
}

void assignKnights(int sx, int sy, int n, int m){

    int ddis[35][35];
    memset(ddis, -1, sizeof(ddis));

    ddis[sx][sy] = 0;

    queue<pii> q;

    q.push(make_pair(sx, sy));

    while(!q.empty()){

        pii top = q.front();
        q.pop();

        for(int i = 0; i<4; i++){
            int tx = top.first + fx[i];
            int ty = top.second + fy[i];

            if(valid(tx, ty, n, m) && ddis[tx][ty] == -1){

                ddis[tx][ty] = ddis[top.first][top.second] + 1;

                if(grid[tx][ty] == 'm'){
                    addEdge(grid[sx][sy]-64, mp[make_pair(tx, ty)], 1, ddis[tx][ty]);
                }
                q.push(make_pair(tx, ty));
            }
        }


    }


}

int main()
{


    int test, cs = 0;

    scanf("%d", &test);

    while(test--)
    {
        int n, m, k;

        scanf("%d %d %d", &n, &k, &m);

        int tick = k + 1;

        // knights: 1 - K, source: 0, sink :

        init();
        mp.clear();


        for(int i = 0; i<n; i++){
            scanf("%s", grid[i]);

            for(int j = 0; j<n; j++){
                if(grid[i][j] == 'm'){
                    mp[make_pair(i, j)] = tick++;
                }
            }
        }

        int source = 0, sink = tick;

        vector<int> limit(k+2);

        for(int i = 1; i<=k; i++) cin>>limit[i];


        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] >='A' && grid[i][j]<='Z'){

                    addEdge(source, grid[i][j]-64, limit[grid[i][j]-64], 0);
                    assignKnights(i, j, n, n);
                //    cout<<"*"<<endl;
                }
                else if(grid[i][j] == 'm'){
                    addEdge(mp[make_pair(i, j)], sink, 1, 0);
                }
            }
        }

        pair<int, int> flow = MCMF(source, sink, tick);

        printf("Case %d: %d\n", ++cs, flow.second);
    }

    return 0;
}

