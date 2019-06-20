#include<bits/stdc++.h>
using namespace std;
const int mx=1005;
 
vector<int> graph[mx];
vector<int> cost[mx];
int d[mx];
bool vis[mx];
 
struct node{
 
        int u, w;
 
        node(int a, int b){
            u=a;   w=b;
        }
 
        bool operator<(const node &p) const{
            return w>p.w;
        }
};
 
int dijkstra(int n)
{
        memset(d, 1, sizeof d);
        memset(vis, -1, sizeof vis);
 
        priority_queue<node> q;
        q.push(node(1, 0));
        d[1]=0;
 
        while(!q.empty())
        {
                node top=q.top();
                q.pop();
                int u=top.u;
                if(u==n)    return d[n];
 
                for(int i=0; i<graph[u].size(); i++)
                {
                    int v=graph[u][i];
 
                    if(d[v]>d[u]+cost[u][i])
                    {
                        d[v]=d[u]+cost[u][i];
                        vis[v]=1;
                        q.push(node(v, d[v]));
                    }
                }
 
        }
        return -1;
}
 
 
int main()
{
 
        int n, edge, x, y, z, test, i;
 
        scanf("%d", &test);
 
        for(i=1; i<=test; i++)
        {
            scanf("%d %d", &n, &edge);
 
            while(edge--)
            {
                scanf("%d %d %d", &x, &y, &z);
 
                graph[x].push_back(y);
                graph[y].push_back(x);
 
                cost[x].push_back(z);
                cost[y].push_back(z);
            }
 
            x=dijkstra(n);
 
            if(x==-1)   printf("Case %d: Impossible\n",i);
            else printf("Case %d: %d\n",i, x);
 
            for(int x=0; x<mx; x++)
            {
                graph[x].clear();
                cost[x].clear();
            }
 
        }
 
    return 0;
 
}
 