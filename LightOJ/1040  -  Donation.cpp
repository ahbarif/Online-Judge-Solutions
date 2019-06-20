#include<bits/stdc++.h>
using namespace std;

int par[55], a[55][55], n;
bool vis[55];
std::vector<int> g[55];

struct edge
{
	int u, v, w;

	edge() {}

	edge(int _u, int _v, int _w){
		u = _u;
		v = _v;
		w = _w;
	}

	bool operator<(const edge &p)const{
		return w<p.w;
	}
};

void makeset()
{
	for(int i=0; i<55; i++)	par[i] = i;
	for(int i=0; i<55; i++)	g[i].clear();
}

int find_par(int n)
{
	if (par[n]==n) return n;
	par[n]=find_par(par[n]);
	return par[n];
}

void merge(int x, int y)
{
	int u = find_par(x);
	int v = find_par(y);

	if(u==v)    return;
	par[u] = v;
}

void dfs(int u)
{

	vis[u] = 1;

	for(int i=0; i<g[u].size(); i++)
	{
		int v = g[u][i];

		if(vis[v]==0)	dfs(v);

	}
}

bool isConnected()
{

	memset(vis, 0, sizeof (vis));
	int cnt = 0, i;

	for(i=1; i<=n; i++)
	{
		if(vis[i]==false)
		{
			++cnt;
			dfs(i);
		}
	}


	return cnt==1;
}

int MST()
{
	vector<edge> E;

	int x, y, z, i, sum = 0, j;

	for(i=1; i<=n; i++)
	{
		for(j=1; j<=n; j++)
		{
			if(a[i][j]!=0)
			{
				E.push_back(edge(i, j, a[i][j]));
			}
		}
	}

	sort(E.begin(), E.end());

	for(i=0; i<E.size(); i++)
	{
		x = E[i].u;
		y = E[i].v;
		z = E[i].w;
		sum+=z;

		if(find_par(x)==find_par(y))    continue;
		else
		{
			merge(x, y);
			sum-=z;
		}
	}

	return sum;

}

int main()
{

		int test, cs = 1, i, j;

		scanf("%d", &test);

		while(test--)
		{
			scanf("%d", &n);

			makeset();

			for(i=1; i<=n; i++)
			{
				for(j=1; j<=n; j++)
				{
					scanf("%d", &a[i][j]);
					if(a[i][j]!=0)
					{
						g[i].push_back(j);
						g[j].push_back(i);
					}
				}
			}

			if(!isConnected())	printf("Case %d: -1\n", cs++);

			else printf("Case %d: %d\n",cs++, MST());

		}

	return 0;

}
