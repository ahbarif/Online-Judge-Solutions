#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int parent[maxn], P[maxn][25], L[maxn];
vector<int> adj[maxn];
void dfs(int u, int depth)
{
     L[u] = depth;
     for (int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if (L[v] == -1)
        {
            parent[v] = u;
            dfs(v, depth + 1);
        }
    }
}
void LCA_init(int root, int n)
{
    memset(L, -1, sizeof(L));
    dfs(root, 0);
     memset(P, -1, sizeof(P));
     for (int i = 1; i <= n; i++)
        P[i][0] = parent[i];
     for (int j = 1; (1 << j) < n; j++)
    {
        for (int i = 1; i <= n; i++)
        {
             if (P[i][j - 1] != -1)
            {
                P[i][j] = P[P[i][j - 1]][j - 1];
            }
        }
    }
}
int LCA_query(int u, int v)
{
     if (L[u] < L[v])
    {
        swap(u, v);
    }
     int dist = L[u] - L[v];
     while (dist > 0)
    {
        int raise_by = log2(dist);
        u = P[u][raise_by];
        dist -= (1 << raise_by);
    }
     if (u == v)
    {
        return u;
    }
     for (int j = 24; j >= 0; --j)
    {
        if ((P[u][j] != -1) and (P[u][j] != P[v][j]))
        {
            u = P[u][j];
            v = P[v][j];
        }
    }
    return parent[u]; //or parent[v]
}
void init()
{
     for (int i = 0; i < maxn; i++)
        adj[i].clear();
    memset(parent, -1, sizeof(parent));
}
int main()
{
    //    freopen("in.txt", "r", stdin);
     int test, cs = 0;
     scanf("%d", &test);
     while (test--)
    {
         init();
         int n, m, x;
         scanf("%d", &n);
         for (int i = 1; i <= n; i++)
        {
            scanf("%d", &m);
            while(m--){
                scanf("%d", &x);
                adj[i].push_back(x);
            }
        }
         LCA_init(1, n);
         int q;
         scanf("%d", &q);
         printf("Case %d:\n", ++cs);
         for (int i = 0; i < q; i++)
        {
            int u, v;
             scanf("%d %d", &u, &v);
             int x = LCA_query(u, v);
             printf("%d\n", LCA_query(u, v));
        }
    }
