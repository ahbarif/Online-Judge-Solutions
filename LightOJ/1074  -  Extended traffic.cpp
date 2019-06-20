#include<bits/stdc++.h>
using namespace std;

#define inf INT_MAX

int dis[205], a[205];

struct edge{

    int u, v, w;

	edge(){}

	edge(int _u, int _v, int _w)
	{
        u = _u;
        v = _v;
        w = _w;

	}
};

vector<edge> E;

void bellman_ford(int source, int n)
{
	for(int i=0; i<205; i++)	dis[i] = inf;

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

	// for(int j=0; j<E.size(); j++)
	// {
	// 		int u = E[j].u;
	// 		int v = E[j].v;
	// 		int w = E[j].w;

	// 		if(dis[u] + w < dis[v] && dis[u]!=inf)
	// 		{
	// 			//puts("Cycle deteted");
				
	// 		}
	// }

}
int main()
{
		
		int test, cs = 1;

		scanf("%d", &test);
		
		while(test--)
		{
	
			int n, m, j, i, query, d, x, y;


			scanf("%d", &n);
			E.clear();

			for(i=1; i<=n; i++)	scanf("%d", &a[i]);

			scanf("%d", &m);

			while(m--)
			{
				scanf("%d %d", &x, &y);

				int c = (a[y]-a[x])*(a[y]-a[x])*(a[y]-a[x]);

				E.push_back(edge(x, y, c));
			}

			bellman_ford(1, n);


			scanf("%d", &query);

			printf("Case %d:\n", cs++);

			while(query--)
			{
				scanf("%d", &d);

				if(dis[d]<3 || dis[d]==inf)	printf("?\n");

				else printf("%d\n", dis[d]);
			}

		}	

	return 0;
}
