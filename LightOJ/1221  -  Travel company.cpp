#include<bits/stdc++.h>
using namespace std;
 
#define inf 10000000
 
int dis[105];
 
struct edge
{
    int u, v, w;
 
    edge() {}
 
    edge(int u, int v, int w):u(u), v(v), w(w) {}
};
 
vector<edge> E;
 
void bellman_ford(int source, int n)
{
    for(int i=0; i<105; i++)    dis[i] = inf;
 
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
 
                puts("YES");
                return;
        }
    }
 
    puts("NO");
    return;
 
}
 
int main()
{
 
    int test, cs = 0;
 
    scanf("%d", &test);
 
    while(test--)
    {
 
        int n, m, z, x, y, p, i, e;
 
        scanf("%d %d %d", &n, &m, &p);
 
        E.clear();
 
 
        while(m--)
        {
            scanf("%d %d %d %d", &x, &y, &i, &e);
 
            E.push_back(edge(x, y, e*p-i));
        }
 
        for(int i = 0; i<n; i++)    E.push_back(edge(n, i, 0));
 
        printf("Case %d: ", ++cs);
 
        bellman_ford(n, n+1);
 
    }
 
    return 0;
}

