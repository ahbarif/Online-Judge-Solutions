#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
const int sz = 30005;
vector<int> graph[sz];
map<pii, int> cost;
 
bool vis[sz];
int dis[sz];
 
void bfs(int src)
{
        memset(vis, 0, sizeof vis);
        memset(dis, 0, sizeof dis);
        queue<int> q;
        q.push(src);
        vis[src]=1;
 
        while(!q.empty())
        {
                int top = q.front();
                q.pop();
 
                for(int i=0; i<graph[top].size(); i++)
                {
                        int x=graph[top][i];
 
                        if(vis[x]==0)
                        {
                            vis[x]=1;
                            dis[x]=dis[top]+cost[make_pair(top, x)];
                            q.push(x);
                        }
                }
        }
 
}
 
 
int main()
{
 
        int test, caseno=0;
 
        scanf("%d", &test);
 
        while(test--)
        {
                    int node, edge, x, y, z, i;
 
                scanf("%d", &node);
 
                for(i=1; i<node; i++)
                {
                    scanf("%d %d %d", &x, &y, &z);
                    graph[x].push_back(y);
                    graph[y].push_back(x);
                    cost[make_pair(x, y)]=z;
                    cost[make_pair(y, x)]=z;
                }
 
                bfs(0); x=0; y=0; z=0;
 
                for(i=0; i<node; i++)
                {
                    if(dis[i]>y)
                    {
                        y=dis[i];
                        x=i;
                    }
                }
 
                bfs(x);
 
                for(i=0; i<node; i++)   z=max(z, dis[i]);
 
                printf("Case %d: %d\n", ++caseno, z);
 
                for(i=0; i<sz; i++)   graph[i].clear();
                cost.clear();
 
        }
 
 
        return 0;
}
 