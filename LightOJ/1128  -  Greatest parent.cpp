#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;
int parent[maxn], P[maxn][25], L[maxn], coin[maxn];
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

    for (int i = 0; i < n; i++)
        P[i][0] = parent[i];

    for (int j = 1; (1 << j) < n; j++)
    {
        for (int i = 0; i < n; i++)
        {

            if (P[i][j - 1] != -1)
            {
                P[i][j] = P[P[i][j - 1]][j - 1];
            }
        }
    }
}

int LCA_query(int u, int depth)
{

  	int dist = depth;

    while (dist > 0)
    {
        int raise_by = log2(dist);
        u = P[u][raise_by];
        dist -= (1 << raise_by);
    }

	return u;

}

void init()
{

    for (int i = 0; i < maxn; i++)    adj[i].clear();
    memset(parent, -1, sizeof(parent));
}

int query(int u, int v){

    for (int j = 24; j >= 0; --j)
    {
        if ((P[u][j] != -1) and (coin[P[u][j]] >= v))
        {
            u = P[u][j];
        }
    }

    return u;


}

int main()
{

 //      freopen("in.txt", "r", stdin);

    int test, cs = 0;

    scanf("%d", &test);

    while (test--)
    {

        init();

        int n, m, x, q;

        scanf("%d %d", &n, &q);

        coin[0] = 1;

        for (int i = 1; i <n; i++)
        {
            int u, v;

			cin>>u>>coin[i];
			adj[u].push_back(i);
			adj[i].push_back(u);

        }

        LCA_init(0, n);

        printf("Case %d:\n", ++cs);

        for (int i = 0; i < q; i++)
        {
            int u, v;

            scanf("%d %d", &u, &v);

            int x = query(u, v);

      //      cout<<"brute = "<<q3(u, v)<<endl;

            printf("%d\n", x);
        }
    }
}

