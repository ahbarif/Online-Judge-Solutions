#include<bits/stdc++.h>
using namespace std;

const int mx = 10005;
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

int fdis[mx], rdis[mx];

vector<pair<int, int> > adj_f[mx];
vector<pair<int, int> > adj_r[mx];

void init()
{
    for(int i = 0; i<mx; i++)
    {
        adj_f[i].clear();
        adj_r[i].clear();
        fdis[i] = inf;
        rdis[i] = inf;
    }

}

int dijkstra(int src, vector<pair<int, int> > adj[], int dis[])
{

    dis[src] = 0;

    priority_queue<node> q;

    q.push(node(src, 0));

    while(!q.empty())
    {
        node top = q.top();

        q.pop();

        int u = top.u;

        for(int i=0; i<adj[u].size(); i++)
        {
            pair<int, int> v = adj[u][i];

            if(dis[v.first] > dis[u] + v.second)
            {
                dis[v.first] = dis[u] + v.second;
                q.push(node(v.first, dis[v.first]));
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

        init();

        int n, m, src, dst, toll;

        scanf("%d %d %d %d %d", &n, &m, &src, &dst, &toll);

        while(m--)
        {
            int u, v, w;

            scanf("%d %d %d", &u, &v, &w);

            adj_f[u].push_back(make_pair(v, w));
            adj_r[v].push_back(make_pair(u, w));
        }

        dijkstra(src, adj_f, fdis);

        dijkstra(dst, adj_r, rdis);

        int res = -1;

        for(int i = 1; i<=n; i++)
        {
            for(int j = 0; j<adj_f[i].size(); j++)
            {
                int v = adj_f[i][j].first;
                int w = adj_f[i][j].second;

                int tot = fdis[i] + rdis[v] + w;
             //   cout<<tot<<endl;

                if(tot<=toll)   res = max(res, w);
            }
        }

        printf("Case %d: %d\n", ++cs, res);

    }

}

