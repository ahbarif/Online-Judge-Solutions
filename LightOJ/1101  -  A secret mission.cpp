#include <bits/stdc++.h>
using namespace std;

const int maxn = 50005;
int parent[maxn], P[maxn][25], L[maxn], M[maxn][25], d[maxn];
vector<int> adj[maxn], cost[maxn];

struct edge
{
	int u, v, w;
	edge() {}
	edge(int u, int v, int w) : u(u), v(v), w(w) {}

	bool operator<(const edge &p) const
	{
		return w < p.w;
	}
};

vector<edge> E;

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
	d[root] = 0;
	dfs(root, 0);

	memset(M, 0, sizeof(M));
	memset(P, -1, sizeof(P));

	for (int i = 1; i <= n; i++)
	{
		P[i][0] = parent[i];
		M[i][0] = d[i];
	}

	for (int j = 1; (1 << j) < n; j++)
	{
		for (int i = 1; i <= n; i++)
		{

			if (P[i][j - 1] != -1)
			{
				P[i][j] = P[P[i][j - 1]][j - 1];
				M[i][j] = max(M[i][j], max(M[i][j - 1], M[P[i][j - 1]][j - 1]));
			}
		}
	}
}

int LCA_query(int u, int v)
{

	int maxa = 0;

	if (u == v)
		return 0;

	if (L[u] < L[v])
	{
		swap(u, v);
	}

	int dist = L[u] - L[v];

	while (dist > 0)
	{
		int raise_by = log2(dist);

		maxa = max(maxa, M[u][raise_by]);

		u = P[u][raise_by];
		dist -= (1 << raise_by);
	}

	if (u == v)
	{
		return maxa;
	}

	for (int j = 24; j >= 0; --j)
	{
		if ((P[u][j] != -1) and (P[u][j] != P[v][j]))
		{
			maxa = max(maxa, M[u][j]);
			maxa = max(maxa, M[v][j]);

			u = P[u][j];
			v = P[v][j];
		}
	}

	maxa = max(maxa, d[u]);
	maxa = max(maxa, d[v]);

	return maxa;
}

int find_par(int n)
{
	if (parent[n] == n)		return n;
	parent[n] = find_par(parent[n]);
	return parent[n];
}

void union_(int x, int y)
{
	int u = find_par(x);
	int v = find_par(y);

	if (u == v)		return;
	parent[u] = v;
}

void Kruskal(int n)
{
	for (int i = 0; i <= n; i++)	parent[i] = i;

	sort(E.begin(), E.end());

	for (int i = 0; i < E.size(); i++)
	{
		int x = E[i].u;
		int y = E[i].v;
		int z = E[i].w;

		if (find_par(x) == find_par(y))
			continue;

		else
		{
			union_(x, y);
			adj[x].push_back(y);
			adj[y].push_back(x);
			cost[x].push_back(z);
			cost[y].push_back(z);
		}
	}
}

void init()
{

	for (int i = 0; i < maxn; i++)
	{
		adj[i].clear();
		cost[i].clear();
	}
	E.clear();
	memset(parent, -1, sizeof(parent));
}

int main()
{

//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

	int test, cs = 0;

	scanf("%d", &test);

	while (test--)
	{

		init();

		int n, m;

		scanf("%d %d", &n, &m);

		for (int i = 1; i <=m; i++)
		{
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			E.push_back(edge(u, v, w));
		}

		Kruskal(n);

		LCA_init(1, n);

		int q;

		scanf("%d", &q);

		printf("Case %d:\n", ++cs);

		for (int i = 0; i < q; i++)
		{
			int u, v;

			scanf("%d %d", &u, &v);

			int x = LCA_query(u, v);

			printf("%d\n", x);
		}
	}
}
