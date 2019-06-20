#include <bits/stdc++.h>
using namespace std;

bool vis[105];
int dis[105], d2[105];
vector<int> g[105];

void init()
{
    memset(vis, 0, sizeof vis);
    memset(dis, 0, sizeof dis);
}

inline void bfs(int node)
{
    init();
    vis[node] = 1;
    dis[node] = 0;

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
                dis[u] = dis[top] + 1;
                vis[u] = 1;
            }
        }
    }

}

void solve(int cs)
{
    for(int i=0; i<105; i++)    g[i].clear();
    int n, m, src, dst;

    scanf("%d %d", &n, &m);

    while(m--)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);

    }

    scanf("%d %d", &src, &dst);

    bfs(src);

    for(int i=0; i<n; i++)  d2[i] = dis[i];

    bfs(dst);

    int res = INT_MIN;

    for(int i=0; i<n; i++) res = max(res, d2[i]+dis[i]);

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
