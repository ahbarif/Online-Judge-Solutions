#include <bits/stdc++.h>
using namespace std;
 
struct node
{
    int u, inDegree, outDegree;
 
    node() {}
 
    node(int _u, int _iD, int _oD)
    {
        u = _u;
        inDegree = _iD;
        outDegree = _oD;
 
    }
 
    bool operator < (const node &p) const
    {
        if(inDegree!=p.inDegree) return inDegree<p.inDegree;
        else return outDegree > p.outDegree;
    }
};
 
vector<int> g[10005];
bool vis[10004];
int n, m;
 
node a[10005];
 
void init()
{
    for(int i=0; i<10005; i++)  g[i].clear();
    memset(vis, 0, sizeof vis);
}
 
void dfs(int u)
{
    vis[u] = 1;
 
    int i, v, sz = g[u].size();
 
    for(i=0; i<sz; i++)
    {
        v = g[u][i];
 
        if(vis[v]==0)
        {
            dfs(v);
        }
    }
}
 
int main()
{
 
    int test, cs = 1;
 
    scanf("%d", &test);
 
    while(test--)
    {
        init();
 
        scanf("%d %d", &n, &m);
 
        for(int i=1; i<=n; i++) a[i].u = i, a[i].inDegree = 0, a[i].outDegree = 0;
 
        while(m--)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            g[x].push_back(y);
            a[y].inDegree++;
            a[x].outDegree++;
        }
 
        sort(a+1, a+n+1);
 
        int res = 0;
 
        for(int i=1; i<=n; i++)
        {
            if(vis[a[i].u]==0)
            {
                ++res;
                dfs(a[i].u);
            }
        }
 
        printf("Case %d: %d\n", cs++, res);
    }
 
 
 
    return 0;
 
}
 