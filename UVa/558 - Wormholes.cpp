#include<bits/stdc++.h>
using namespace std;

#define inf 10000000

int dis[2005];

struct edge{

    int u, v, w;

	edge(){}
    edge(int u, int v, int w):u(u), v(v), w(w){}
};

vector<edge> E;

void bellman_ford(int source, int n)
{
	for(int i=0; i<2005; i++)	dis[i] = inf;

	dis[source] = 0;

	for(int i=1; i<n; i++)
	{
		for(int j=0; j<E.size(); j++)
		{
			int u = E[j].u;
			int v = E[j].v;
			int w = E[j].w;

			if(dis[u] + w < dis[v]  && dis[u]!=inf)
			{
				dis[v] = dis[u] + w;
			}
		}
	}

	 for(int j=0; j<E.size(); j++)
	 {
	 		int u = E[j].u;
	 		int v = E[j].v;
	 		int w = E[j].w;

	 		if(dis[u] + w < dis[v] && dis[u]!=inf)
	 		{
	 			puts("possible");
	 			return;

	 		}
	 }

	 puts("not possible");
	 return;

}

int main()
{

		int test, cs = 1;

		scanf("%d", &test);

		while(test--)
		{

			int n, m, z, x, y;

			scanf("%d %d", &n, &m);

			E.clear();

			while(m--)
			{
				scanf("%d %d %d", &x, &y, &z);

				E.push_back(edge(x, y, z));
			}

			bellman_ford(1, n);

		}

	return 0;
}
