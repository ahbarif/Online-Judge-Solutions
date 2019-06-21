#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;
int parent[maxn], P[maxn][25], L[maxn], M[maxn][25], d[maxn], Mn[maxn][25];
vector<int> adj[maxn], cost[maxn];

void dfs(int u, int depth)
{

    L[u] = depth;

    for (int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if (L[v] == -1)
        {
            parent[v] = u;
			d[v] = cost[u][i];
            dfs(v, depth + 1);
        }
    }
}

void LCA_init(int root, int n)
{
    memset(L, -1, sizeof(L));
    dfs(root, 0);

	memset(M, 0, sizeof(M));
	memset(Mn, 1, sizeof(Mn));

    memset(P, -1, sizeof(P));

    for (int i = 1; i <= n; i++){
        P[i][0] = parent[i];
		M[i][0] = d[i];
		Mn[i][0] = d[i];
	}

    for (int j = 1; (1 << j) < n; j++)
    {
        for (int i = 1; i <= n; i++)
        {

            if (P[i][j - 1] != -1)
            {
                P[i][j] = P[P[i][j - 1]][j - 1];
				M[i][j] = max(M[i][j], max(M[i][j-1], M[P[i][j-1]][j-1]));
				Mn[i][j] = min(Mn[i][j], min(Mn[i][j-1], Mn[P[i][j-1]][j-1]));

			}
        }
    }
}

pair<int, int> LCA_query(int u, int v)
{

	int maxa = 0, mina = 1000005;

	if(u==v) return make_pair(0, 0);

    if (L[u] < L[v]){
        swap(u, v);
    }

    int dist = L[u] - L[v];

    while (dist > 0)
    {
        int raise_by = log2(dist);

		maxa = max(maxa, M[u][raise_by]);
		mina = min(mina, Mn[u][raise_by]);

        u = P[u][raise_by];
        dist -= (1 << raise_by);	
    }

    if (u == v){
        return make_pair(mina, maxa);
    }


    for (int j = 24; j >= 0; --j){
        if ((P[u][j] != -1) and (P[u][j] != P[v][j]))
        {
			maxa = max(maxa, M[u][j]);
			maxa = max(maxa, M[v][j]);

			mina = min(mina, Mn[u][j]);
			mina = min(mina, Mn[v][j]);
			
			u = P[u][j];
            v = P[v][j];
        }
    }

	maxa = max(maxa, d[u]);
	maxa = max(maxa, d[v]);

	mina = min(mina, d[u]);
	mina = min(mina, d[v]);
   
	return make_pair(mina, maxa);
}

void init()
{

    for (int i = 0; i < maxn; i++){
        adj[i].clear();
		cost[i].clear();
	}
    memset(parent, -1, sizeof(parent));
}
int main()
{


    int test, cs = 0;

    scanf("%d", &test);

    while (test--)
    {

        init();

        int n;

        scanf("%d", &n);

        for (int i = 1; i < n; i++)
        {
				int u, v, w;
				scanf("%d %d %d", &u, &v, &w);
                adj[u].push_back(v);
				adj[v].push_back(u);
                cost[u].push_back(w);
                cost[v].push_back(w);
        }

        LCA_init(1, n);

        int q;

        scanf("%d", &q);

        printf("Case %d:\n", ++cs);

        for (int i = 0; i < q; i++)
        {
            int u, v;

            scanf("%d %d", &u, &v);

            pair<int, int> x = LCA_query(u, v);

            printf("%d %d\n", x.first, x.second);
        }
    }
}
