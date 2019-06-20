#include <bits/stdc++.h>
using namespace std;

const int sz = 30002;
bool vis[sz];
int dis[sz], d2[sz], mx = 0, mxn;
vector<int> g[sz], cost[sz];

inline void bfs(int node)
{
    memset(vis, 0, sizeof vis);

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
                dis[u] = dis[top] + cost[top][i];
                if(dis[u] >mx)
                {
                    mx = dis[u];
                    mxn = u;
                }
                vis[u] = 1;
            }
        }
    }

}

void solve(int cs)
{
    for(int i=0; i<sz; i++)    g[i].clear(), cost[i].clear();

    int n, i;

    scanf("%d", &n);

    for(i=1; i<n; i++)
    {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        g[x].push_back(y);
        g[y].push_back(x);
        cost[x].push_back(z);
        cost[y].push_back(z);
    }

    int src1, src2;

    mx = -1;
    bfs(0);

    src1 = mxn;
    mx = -1;
    bfs(src1);

    for(i=0; i<n; i++)  d2[i] = dis[i];

    src2 = mxn;
    bfs(src2);

    printf("Case %d:\n", cs);

    for(i=0; i<n; i++)  printf("%d\n", max(dis[i], d2[i]));

}

int main()
{
    int t, cs = 1;

    scanf("%d", &t);

    while(t--)
    {
        solve(cs++);
    }

    return 0;
}
