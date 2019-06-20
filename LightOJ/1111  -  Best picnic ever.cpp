#include <bits/stdc++.h>
using namespace std;

bool vis[1005];
int dis[1005];
vector<int> g[1005];

inline void bfs(int node)
{
    memset(vis, 0, sizeof vis);

    vis[node] = 1;

    dis[node]++;

    queue<int> q;
    q.push(node);

    while(!q.empty())
    {
        int top = q.front();
        q.pop();

        for(int i=0; i<g[top].size(); i++)
        {
            int u = g[top][i];
            if(vis[u]==0)
            {
                q.push(u);
                dis[u]++;
                vis[u] = 1;
            }
        }
    }

}

void solve(int cs)
{
    for(int i=0; i<1005; i++)    g[i].clear();
    memset(dis, 0, sizeof dis);

    int n, m, k;
    vector<int> nodes;

    scanf("%d %d %d", &k, &n, &m);

    for(int i=0; i<k; i++)
    {
        int x;
        scanf("%d", &x);
        nodes.push_back(x);
    }

    while(m--)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
    }

    for(int i=0; i<nodes.size(); i++)   bfs(nodes[i]);

    int res = 0;

    for(int i=1; i<=n; i++) res = res+(dis[i]==k);

    printf("Case %d: %d\n", cs, res);
}

int main()
{
        int t , cs = 1;

        scanf("%d", &t);

        while(t--)
        {
            solve(cs++);
        }

        return 0;
}
